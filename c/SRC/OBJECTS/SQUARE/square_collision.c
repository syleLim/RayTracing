/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:15:42 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:08:30 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

static double	equation(t_square *square, t_vec origin, t_vec dir)
{
	double t;

	if (vdot(square->normal, dir) == 0)
		return (-1.);
	t = (vdot(square->normal, square->pos)
		- vdot(square->normal, origin))
		/ vdot(square->normal, dir);
	return (t);
}

static t_bool	check_inside(t_vec pos, t_square *square)
{
	t_vec		ab;
	t_vec		ac;
	t_vec		ap;
	double		sol[2];

	vsubtract(ab, square->b, square->a);
	vsubtract(ac, square->c, square->a);
	vadd(ap, square->pos, square->a);
	vsubtract(ap, pos, ap);
	sol[0] = vdot(ap, ab) / vdot(ab, ab);
	sol[1] = vdot(ap, ac) / vdot(ac, ac);
	if (0. < sol[0] && sol[0] < 1. && 0. < sol[1] && sol[1] < 1.)
		return (TRUE);
	return (FALSE);
}

static t_bool	collision(t_vec pos, t_square *square,
								t_vec origin, t_vec dir)
{
	double	t;

	t = equation(square, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, square))
		return (FALSE);
	return (TRUE);
}

void			collision_square(t_square *square,
						t_ray *ray, t_hitter *hitter)
{
	t_vec pos;

	if (collision(pos, square, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, square->normal))
			set_hitter_color(hitter, square->color, square->id);
}

void			shadow_collision_square(t_square *square,
							t_ray *ray, t_hitter *hitter)
{
	t_vec temp;

	if (square->id == hitter->obj_id)
		return ;
	if (collision(temp, square, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
