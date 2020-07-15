#include "objects.h"

t_objs	*init_objs()
{
	t_objs	*objs;

	if (!(objs = malloc(sizeof(t_objs))))
		exit(1);
	objs->num_of_objs = 0;
	objs->sphere_num = 0;
	objs->plane_num = 0;
	objs->triangle_num = 0;
	objs->square_num = 0;
	objs->cylinder_num = 0;
	return (objs);
}

void	add_sphere(t_objs *objs, t_sphere *sphere)
{
	sphere->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->spheres[objs->sphere_num] = sphere;
	++objs->sphere_num;
}

void	add_plane(t_objs *objs, t_plane *plane)
{
	plane->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->planes[objs->plane_num] = plane;
	objs->plane_num++;
}

void	add_triangle(t_objs *objs, t_triangle *triangle)
{
	triangle->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->triangles[objs->triangle_num] = triangle;
	objs->triangle_num++;
}

void	add_square(t_objs *objs, t_square *square)
{
	square->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->squares[objs->square_num] = square;
	objs->square_num++;
}

void	add_cylinder(t_objs *objs, t_cylinder *cylinder)
{
	cylinder->id = objs->num_of_objs;
	cylinder->circles[0]->id = objs->num_of_objs;
	cylinder->circles[1]->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->cylinders[objs->cylinder_num] = cylinder;
	objs->cylinder_num++;
}

void	objs_collision(t_objs *objs, t_ray *ray, t_hitter *hitter)
{
	int i;
	
	clear_hitter(hitter);
	i = -1;
	while (++i < objs->sphere_num)
		collision_sphere(objs->spheres[i], ray, hitter);
	i = -1;
	while (++i < objs->plane_num)
		collision_plane(objs->planes[i], ray, hitter);
	i = -1;
	while (++i < objs->triangle_num)
		collision_triangle(objs->triangles[i], ray, hitter);
	i = -1;
	while (++i < objs->square_num)
		collision_square(objs->squares[i], ray, hitter);
	i = -1;
	while (++i < objs->cylinder_num)
		collision_cylinder(objs->cylinders[i], ray, hitter);
	// TODO : other objects, square, ...
}