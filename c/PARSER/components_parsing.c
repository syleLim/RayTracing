#include "parser.h"

int	parsing_window(t_components *comp, char **info)
{
	double w;
	double h;

	w = ft_atoi(info[1]);
	h = ft_atoi(info[2]);
	if (ft_strslen(info) != 3)
		exit(1);
	set_window(comp->window, w, h);
	set_screen_wh(comp->screen, w, h);
	return (TRUE);
}

int	parsing_ambient(t_light *light, char **info)
{
	vec temp;

	if (ft_strslen(info) != 3)
		exit(1);
	parse_vector(temp, info[2], 256);
	vmultiple(temp, temp, ft_atof(info[1]));
	set_light_ambient(light, temp);
	return (TRUE);
}

int	parsing_camera(t_components *comp, char **info)
{
	vec temp;

	if (ft_strslen(info) != 4)
		exit(1);
	parse_vector(temp, info[1], 1);
	set_camera_pos(comp->camera, temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	camera_rotate(comp->camera, temp);
	set_camera_fov(comp->camera, ft_atof(info[3]));
	set_screen_vector(comp->screen, comp->camera);
	return (TRUE);
}

int	parsing_light(t_light *light, char **info)
{
	vec	temp;

	if (ft_strslen(info) != 4)
		exit(1);
	parse_vector(temp, info[1], 1);
	set_light_pos(light, temp);
	parse_vector(temp, info[3], 256);
	vmultiple(temp, temp, ft_atof(info[2]));
	set_light_color(light, temp);
	return (TRUE);
}