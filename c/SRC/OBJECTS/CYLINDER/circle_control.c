/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:52:30 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:02:29 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void			set_circle_pos(t_circle *circle, t_vec pos)
{
	vcopy(circle->pos, pos);
}

void			set_circle_normal(t_circle *circle, t_vec normal)
{
	vcopy(circle->normal, normal);
}

void			set_circle_radius(t_circle *circle, double radius)
{
	circle->radius = radius;
}

void			set_circle_color(t_circle *circle, t_vec color)
{
	vcopy(circle->color, color);
}
