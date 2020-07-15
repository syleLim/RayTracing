#include "parser.h"



static bool	set_components(t_components *comp, char **info)
{
	if (!ft_strcmp(info[0], "R"))
		return (parsing_window(comp, info));
	if (!ft_strcmp(info[0], "A"))
		return (parsing_ambient(comp->light, info));
	if (!ft_strcmp(info[0], "c"))
		return (parsing_camera(comp, info));
	if (!ft_strcmp(info[0], "l"))
		return (parsing_light(comp->light, info));
	return (FALSE);
}

static bool set_objs(t_objs *objs, char **info)
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

static void	specifier(t_components *comp, t_objs *objs, char *line)
{
	char	**info;
	int		checker;

	checker = 0;
	if (!(info = ft_split(line, ' ')))
		exit(1);
	if (info[0] == NULL)
		return ;
	checker = set_components(comp, info);
	checker += set_objs(objs, info);
	ft_free_strs(info);
	if (checker == 0)
		exit(1);
}

void		parsing(int fd, t_objs *objs, t_components *comp)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		specifier(comp, objs, line);
		free(line);
		line = NULL;
	}
}