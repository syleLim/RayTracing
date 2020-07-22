/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:19:48 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:09:50 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

void		set_normal(t_triangle *triangle)
{
	t_vec v1;
	t_vec v2;

	vsubtract(v1, triangle->a, triangle->b);
	vsubtract(v2, triangle->a, triangle->c);
	vcross(triangle->normal, v1, v2);
	vnormalize(triangle->normal);
}

void		set_triangle_point_a(t_triangle *triangle, t_vec pos)
{
	vcopy(triangle->a, pos);
	set_normal(triangle);
}

void		set_triangle_point_b(t_triangle *triangle, t_vec pos)
{
	vcopy(triangle->b, pos);
	set_normal(triangle);
}

void		set_triangle_point_c(t_triangle *triangle, t_vec pos)
{
	vcopy(triangle->c, pos);
	set_normal(triangle);
}

void		set_triangle_color(t_triangle *triangle, t_vec color)
{
	vcopy(triangle->color, color);
}
