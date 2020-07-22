/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:11:34 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:05:59 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

static double	equation(t_plane *plane, t_vec origin, t_vec dir)
{
	double t;

	if (vdot(plane->normal, dir) == 0)
		return (-1.);
	t = (vdot(plane->normal, plane->point)
		- vdot(plane->normal, origin))
		/ vdot(plane->normal, dir);
	return (t);
}

static t_bool	collision(t_vec pos, t_plane *plane,
								t_vec origin, t_vec dir)
{
	double t;

	t = equation(plane, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	return (TRUE);
}

void			collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter)
{
	t_vec pos;

	if (collision(pos, plane, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, plane->normal))
			set_hitter_color(hitter, plane->color, plane->id);
}

void			shadow_collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter)
{
	t_vec temp;

	if (plane->id == hitter->obj_id)
		return ;
	if (collision(temp, plane, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
