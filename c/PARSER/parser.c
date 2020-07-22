/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:31:24 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:18:21 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	set_components(t_components *comp, char **info, int ra[2])
{
	if (!ft_strcmp(info[0], "R"))
	{
		if (ra[0] != 0)
			error_exit("Error\n\tDouble setting Window");
		else
		{
			ra[0]++;
			return (parsing_window(comp, info));
		}
	}
	if (!ft_strcmp(info[0], "A"))
	{
		if (ra[1] != 0)
			error_exit("Error\n\tDouble setting Window");
		else
		{
			ra[1]++;
			return (parsing_ambient(comp->ambient, info));
		}
	}
	if (!ft_strcmp(info[0], "c"))
		return (parsing_camera(comp, info));
	if (!ft_strcmp(info[0], "l"))
		return (parsing_light(comp, info));
	return (FALSE);
}

static t_bool	set_objs(t_objs *objs, char **info)
{
	if (!ft_strcmp(info[0], "sp"))
		return (parsing_sphere(objs, info));
	if (!ft_strcmp(info[0], "pl"))
		return (parsing_plane(objs, info));
	if (!ft_strcmp(info[0], "sq"))
		return (parsing_square(objs, info));
	if (!ft_strcmp(info[0], "cy"))
		return (parsing_cylinder(objs, info));
	if (!ft_strcmp(info[0], "tr"))
		return (parsing_triangle(objs, info));
	return (FALSE);
}

static void		specifier(t_components *comp, t_objs *objs,
								char *line, int ra[2])
{
	char	**info;
	int		checker;

	checker = 0;
	if (!(info = ft_split(line, ' ')))
		error_exit("Error\nMalloc Error Occured");
	if (info[0] == NULL)
		return ;
	checker = set_components(comp, info, ra);
	checker += set_objs(objs, info);
	ft_free_strs(info);
	if (checker == 0)
		error_exit("Error\n\tWrong Specifier");
}

void			parsing(int fd, t_objs *objs, t_components *comp)
{
	char	*line;
	int		ra[2];

	ra[0] = 0;
	ra[1] = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		specifier(comp, objs, line, ra);
		free(line);
		line = NULL;
	}
	if (*line != 0)
		specifier(comp, objs, line, ra);
	free(line);
}
