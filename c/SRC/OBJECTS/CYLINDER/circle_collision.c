/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:53:21 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:02:42 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static double	equation(t_circle *circle, t_vec origin, t_vec dir)
{
	double t;

	if (vdot(circle->normal, dir) == 0)
		return (-1.);
	t = (vdot(circle->normal, circle->pos)
		- vdot(circle->normal, origin))
		/ vdot(circle->normal, dir);
	return (t);
}

static t_bool	check_inside(t_vec pos, t_circle *circle)
{
	t_vec	temp;

	vsubtract(temp, pos, circle->pos);
	if (vdot(temp, temp) < pow(circle->radius, 2))
		return (TRUE);
	return (FALSE);
}

static t_bool	collision(t_vec pos, t_circle *circle,
								t_vec origin, t_vec dir)
{
	double	t;

	t = equation(circle, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, circle))
		return (FALSE);
	return (TRUE);
}

void			collision_circle(t_circle *circle,
						t_ray *ray, t_hitter *hitter)
{
	t_vec pos;

	if (collision(pos, circle, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, circle->normal))
			set_hitter_color(hitter, circle->color, circle->id);
}

void			shadow_collision_circle(t_circle *circle,
							t_ray *ray, t_hitter *hitter)
{
	t_vec temp;

	if (circle->id == hitter->obj_id)
		return ;
	if (collision(temp, circle, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
