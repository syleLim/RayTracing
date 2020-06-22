#include "objects.h"

t_objs	*init_objs()
{
	t_objs	*objs;

	if (!(objs = malloc(sizeof(t_objs))))
		return (NULL);
	objs->sphere_num = 0;
	objs->plane_num = 0;
	objs->triangle_num = 0;
	objs->square_num = 0;
	objs->cylinder_num = 0;
	return (objs);
}

void	add_sphere(t_objs *objs, t_sphere *sphere)
{
	objs->spheres[objs->square_num] = sphere;
	++objs->square_num;
}

void	add_plane(t_objs *objs, t_plane *plane)
{
	objs->planes[objs->plane_num] = plane;
	++objs->plane_num;
}

void	objs_collision(t_objs *objs, t_ray *ray, t_hitter *hitter)
{
	int i;

	i = -1;
	while (++i < objs->sphere_num)
		collision_sphere(objs->spheres[i], ray, hitter);
	i = -1;
	while (++i < objs->plane_num)
		collision_plane(objs->planes[i], ray, hitter);
	// TODO : other objects, square, ...
}