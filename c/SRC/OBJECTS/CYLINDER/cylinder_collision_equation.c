/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision_equation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:04:33 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:31:33 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static void		set_xy(t_vec xy[2], t_cylinder *cylinder,
						t_vec origin, t_vec dir)
{
	t_vec		m;
	t_vec		v;
	double		n;
	double		l;
	double		k;

	vsubtract(v, cylinder->p2, cylinder->p1);
	vsubtract(m, origin, cylinder->p1);
	n = vdot(origin, v) - vdot(cylinder->p1, v);
	l = vdot(v, v);
	k = vdot(v, dir);
	vmultiple(xy[X], v, k / l);
	vsubtract(xy[X], dir, xy[X]);
	vmultiple(xy[Y], v, n / l);
	vsubtract(xy[Y], m, xy[Y]);
}

static double	equation(t_cylinder *cylinder, t_vec xy[2])
{
	double a;
	double b;
	double c;
	double discriminant;

	a = vdot(xy[X], xy[X]);
	b = vdot(xy[X], xy[Y]);
	c = vdot(xy[Y], xy[Y]) - pow(cylinder->diameter, 2);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	if ((-b - sqrt(discriminant)) / a > 0)
		return ((-b - sqrt(discriminant)) / a);
	if ((-b + sqrt(discriminant)) / a > 0)
		return ((-b + sqrt(discriminant)) / a);
	return (-1);
}

static t_bool	check_inside(double t, t_cylinder *cylinder,
								t_vec origin, t_vec dir)
{
	t_vec	v;
	double	checker;

	vsubtract(v, cylinder->p2, cylinder->p1);
	checker = (vdot(origin, v) + t * vdot(dir, v) - vdot(cylinder->p1, v))
						/ vdot(v, v);
	return ((0 <= checker && checker <= 1));
}

t_bool			collision_eq_c(t_vec pos, t_cylinder *cylinder,
								t_vec origin, t_vec dir)
{
	t_vec		xy[2];
	double		t;

	set_xy(xy, cylinder, origin, dir);
	t = equation(cylinder, xy);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(t, cylinder, origin, dir))
		return (FALSE);
	return (TRUE);
}

void			get_normal(t_vec normal, t_vec pos, t_cylinder *cylinder)
{
	t_vec		v;
	t_vec		temp;
	double		a;

	vsubtract(v, cylinder->p2, cylinder->p1);
	a = (vdot(pos, v) - vdot(cylinder->p1, v)) / vdot(v, v);
	vmultiple(temp, v, a);
	vadd(temp, temp, cylinder->p1);
	vsubtract(normal, pos, temp);
	vnormalize(normal);
}
