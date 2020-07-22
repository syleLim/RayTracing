/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:23:58 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 09:25:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objs	*init_objs(void)
{
	t_objs	*objs;

	if (!(objs = malloc(sizeof(t_objs))))
		error_exit("Malloc Error Occuered");
	objs->num_of_objs = 0;
	objs->sphere_num = 0;
	objs->plane_num = 0;
	objs->triangle_num = 0;
	objs->square_num = 0;
	objs->cylinder_num = 0;
	return (objs);
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
}
