/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:32:22 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:06:47 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parsing_window(t_components *comp, char **info)
{
	int		w;
	int		h;
	int		i;

	if (ft_strslen(info) != 3)
		error_exit("Error\n\tComponent Loss in Window");
	if (!check_nums(info[1], FALSE) || !check_nums(info[2], FALSE))
		error_exit("Error\n\tComponent Wrong in Window");
	w = ft_atoi(info[1]);
	h = ft_atoi(info[2]);
	set_window(comp->window, w, h);
	if (comp->screen_nums == 0)
		set_screen_wh(comp->screens[0], w, h);
	else
	{
		i = -1;
		while (++i < comp->screen_nums)
			set_screen_wh(comp->screens[i], w, h);
	}
	return (TRUE);
}

int	parsing_ambient(t_vec ambient, char **info)
{
	t_vec	temp;

	if (ft_strslen(info) != 3)
		error_exit("Error\n\tComponent Loss in Ambient");
	parse_vector(temp, info[2], 256);
	if (!check_nums(info[1], TRUE))
		error_exit("Error\n\tComponent Wrong in Ambient");
	vmultiple(temp, temp, ft_atof(info[1]));
	vcopy(ambient, temp);
	return (TRUE);
}

int	parsing_camera(t_components *comp, char **info)
{
	t_vec temp;

	if (ft_strslen(info) != 4)
		error_exit("Error\n\tComponent Loss in Camera");
	if (comp->camera_nums != 0)
	{
		comp->cameras[comp->camera_nums] = init_camera();
		comp->screens[comp->screen_nums] =
					init_screen(comp->cameras[comp->camera_nums],
				comp->window->width, comp->window->height);
	}
	parse_vector(temp, info[1], 1);
	set_camera_pos(comp->cameras[comp->camera_nums], temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	camera_rotate(comp->cameras[comp->camera_nums], temp);
	!check_nums(info[3], TRUE) || ft_atof(info[3]) < 0 ?
		error_exit("Error\n\tComponent Wrong in Camera") : 0;
	set_camera_fov(comp->cameras[comp->camera_nums], ft_atof(info[3]));
	set_screen_vector(comp->screens[comp->screen_nums],
						comp->cameras[comp->camera_nums]);
	comp->camera_nums++;
	comp->screen_nums++;
	return (TRUE);
}

int	parsing_light(t_components *comp, char **info)
{
	t_vec	temp;

	if (ft_strslen(info) != 4)
		error_exit("Error\n\tComponent Loss in Light");
	if (comp->light_nums != 0)
		comp->lights[comp->light_nums] = init_light();
	parse_vector(temp, info[1], 1);
	set_light_pos(comp->lights[comp->light_nums], temp);
	parse_vector(temp, info[3], 256);
	vmultiple(temp, temp, ft_atof(info[2]));
	set_light_color(comp->lights[comp->light_nums], temp);
	comp->light_nums++;
	return (TRUE);
}
