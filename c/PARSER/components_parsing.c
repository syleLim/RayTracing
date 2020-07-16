#include "parser.h"

int	parsing_window(t_components *comp, char **info)
{
	double 	w;
	double	h;
	int		i;

	w = ft_atoi(info[1]);
	h = ft_atoi(info[2]);
	if (ft_strslen(info) != 3)
		exit(1);
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

int	parsing_ambient(vec ambient, char **info)
{
	vec temp;

	if (ft_strslen(info) != 3)
		exit(1);
	parse_vector(temp, info[2], 256);
	vmultiple(temp, temp, ft_atof(info[1]));
	vcopy(ambient, temp);
	return (TRUE);
}

int	parsing_camera(t_components *comp, char **info)
{
	vec temp;

	if (ft_strslen(info) != 4)
		exit(1);
	if (comp->camera_nums != 0)
	{
		if (!(comp->cameras[comp->camera_nums] = init_camera()))
			exit(1);
		if (!(comp->screens[comp->screen_nums]
			= init_screen(comp->cameras[comp->camera_nums],
				comp->window->width, comp->window->height)))
			exit(1);
	}
	parse_vector(temp, info[1], 1);
	set_camera_pos(comp->cameras[comp->camera_nums], temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	camera_rotate(comp->cameras[comp->camera_nums], temp);
	set_camera_fov(comp->cameras[comp->camera_nums], ft_atof(info[3]));
	set_screen_vector(comp->screens[comp->screen_nums],
						comp->cameras[comp->camera_nums]);
	comp->camera_nums++;
	comp->screen_nums++;
	return (TRUE);
}

int	parsing_light(t_components *comp, char **info)
{
	vec	temp;

	if (ft_strslen(info) != 4)
		exit(1);
	if (comp->light_nums != 0)
	{
		if (!(comp->lights[comp->light_nums] = init_light()))
			exit(1);
	}
	parse_vector(temp, info[1], 1);
	set_light_pos(comp->lights[comp->light_nums], temp);
	parse_vector(temp, info[3], 256);
	vmultiple(temp, temp, ft_atof(info[2]));
	set_light_color(comp->lights[comp->light_nums], temp);
	comp->light_nums++;
	return (TRUE);
}