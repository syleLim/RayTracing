#include "parser.h"

int	parsing_sphere(t_objs *objs, char **info)
{
	t_sphere	*sphere;
	vec		 temp;

	if (ft_strslen(info) != 4)
		exit(1);
	if (!(sphere = init_sphere()))
		exit(1);
	parse_vector(temp, info[1], 1);
	set_sphere_pos(sphere, temp);
	set_sphere_radius(sphere, ft_atof(info[2]));
	parse_vector(temp, info[3], 256);
	set_sphere_color(sphere, temp);
	add_sphere(objs, sphere);
	return (TRUE);
}

int	parsing_plane(t_objs *objs, char **info)
{
	t_plane	*plane;
	vec		 temp;

	if (ft_strslen(info) != 4)
		exit(1);
	if (!(plane = init_plane()))
		exit(1);
	parse_vector(temp, info[1], 1);
	set_plane_point(plane, temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	set_plane_normal(plane, temp);
	parse_vector(temp, info[3], 256);
	set_plane_color(plane, temp);
	add_plane(objs, plane);
	return (TRUE);
}

int	parsing_square(t_objs *objs, char **info)
{
	t_square	*square;
	vec			temp;

	if (ft_strslen(info) != 5)
		exit(1);
	if (!(square = init_square()))
		exit(1);
	parse_vector(temp, info[1], 1);
	set_square_pos(square, temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	set_square_normal(square, temp);
	set_square_size(square, ft_atof(info[3]));
	parse_vector(temp, info[4], 256);
	set_square_color(square, temp);
	add_square(objs, square);
	return (TRUE);
}

int	parsing_cylinder(t_objs *objs, char **info)
{
	t_cylinder	*cylinder;
	vec			temp;

	if (ft_strslen(info) != 6)
		exit(1);
	if (!(cylinder = init_cylinder()))
		exit(1);
	parse_vector(temp, info[1], 1);
	set_cylinder_pos(cylinder, temp);
	parse_vector(temp, info[2], 1);
	vnormalize(temp);
	set_cylinder_normal(cylinder, temp);
	set_cylinder_diameter(cylinder, ft_atof(info[3]));
	set_cylinder_height(cylinder, ft_atof(info[4]));
	parse_vector(temp, info[5], 256);
	set_cylinder_color(cylinder, temp);
	add_cylinder(objs, cylinder);
	return (TRUE);
}

int	parsing_triangle(t_objs *objs, char **info)
{
	t_triangle	*triangle;
	vec			temp;

	if (ft_strslen(info) != 5)
		exit(1);
	if (!(triangle = init_triangle()))
		exit(1);
	parse_vector(temp, info[1], 1);
	set_triangle_point_a(triangle, temp);
	parse_vector(temp, info[2], 1);
	set_triangle_point_b(triangle, temp);
	parse_vector(temp, info[3], 1);
	set_triangle_point_c(triangle, temp);
	parse_vector(temp, info[4], 256);
	set_triangle_color(triangle, temp);
	add_triangle(objs, triangle);
	return (TRUE);
}