/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_collision_equation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:22:07 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:10:01 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

static double	equation(t_triangle *triangle, t_vec origin, t_vec dir)
{
	double t;

	if (vdot(triangle->normal, dir) == 0)
		return (-1.);
	t = (vdot(triangle->normal, triangle->a)
		- vdot(triangle->normal, origin))
		/ vdot(triangle->normal, dir);
	return (t);
}

static t_bool	check_inside_2(t_vec normal, t_vec line[3], t_vec cone[3])
{
	t_vec cross[3];

	vcross(cross[0], line[0], cone[0]);
	vcross(cross[1], line[1], cone[1]);
	vcross(cross[2], line[2], cone[2]);
	if (vdot(normal, cross[0]) > 0 &&
		vdot(normal, cross[1]) > 0 &&
		vdot(normal, cross[2]) > 0)
		return (TRUE);
	return (FALSE);
}

static t_bool	check_inside(t_vec pos, t_triangle *triangle)
{
	t_vec line[3];
	t_vec cone[3];

	vsubtract(line[0], triangle->b, triangle->a);
	vsubtract(line[1], triangle->c, triangle->b);
	vsubtract(line[2], triangle->a, triangle->c);
	vsubtract(cone[0], pos, triangle->a);
	vsubtract(cone[1], pos, triangle->b);
	vsubtract(cone[2], pos, triangle->c);
	return (check_inside_2(triangle->normal, line, cone));
}

t_bool			collision_eq_t(t_vec pos, t_triangle *triangle,
								t_vec origin, t_vec dir)
{
	double	t;

	t = equation(triangle, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, triangle))
		return (FALSE);
	return (TRUE);
}
