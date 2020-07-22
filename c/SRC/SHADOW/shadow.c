/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:57:59 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:30:12 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"

t_bool	shadow_collision(t_objs *objs, t_ray *ray, t_hitter *hitter)
{
	int i;

	i = -1;
	while (++i < objs->sphere_num && !hitter->is_hit)
		shadow_collision_sphere(objs->spheres[i], ray, hitter);
	i = -1;
	while (++i < objs->plane_num && !hitter->is_hit)
		shadow_collision_plane(objs->planes[i], ray, hitter);
	i = -1;
	while (++i < objs->triangle_num && !hitter->is_hit)
		shadow_collision_triangle(objs->triangles[i], ray, hitter);
	i = -1;
	while (++i < objs->square_num && !hitter->is_hit)
		shadow_collision_square(objs->squares[i], ray, hitter);
	i = -1;
	while (++i < objs->cylinder_num && !hitter->is_hit)
		shadow_collision_cylinder(objs->cylinders[i], ray, hitter);
	return (hitter->is_hit);
}

void	check_shadow(t_objs *objs, t_hitter *hitter,
						t_light *light)
{
	t_ray	*shadow_ray;
	t_vec	dir;

	shadow_ray = init_ray();
	set_ray_origin(shadow_ray, hitter->pos);
	vsubtract(dir, light->pos, hitter->pos);
	vnormalize(dir);
	set_ray_dir(shadow_ray, dir);
	hitter->is_hit = FALSE;
	if (shadow_collision(objs, shadow_ray, hitter))
		hitter->is_shadow = TRUE;
	free(shadow_ray);
}
