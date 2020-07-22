/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:59:05 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:03:50 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void			set_cylinder_pos(t_cylinder *cylinder, t_vec pos)
{
	vcopy(cylinder->pos, pos);
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
}

void			set_cylinder_normal(t_cylinder *cylinder, t_vec normal)
{
	t_vec neg_norm;

	vneg(neg_norm, normal);
	vcopy(cylinder->normal, normal);
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
	set_circle_normal(cylinder->circles[0], cylinder->normal);
	set_circle_normal(cylinder->circles[1], neg_norm);
}

void			set_cylinder_diameter(t_cylinder *cylinder, double diameter)
{
	cylinder->diameter = diameter;
	set_circle_radius(cylinder->circles[0], diameter);
	set_circle_radius(cylinder->circles[1], diameter);
}

void			set_cylinder_color(t_cylinder *cylinder, t_vec color)
{
	vcopy(cylinder->color, color);
	set_circle_color(cylinder->circles[0], color);
	set_circle_color(cylinder->circles[1], color);
}

void			set_cylinder_height(t_cylinder *cylinder, double height)
{
	cylinder->height = height;
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
}
