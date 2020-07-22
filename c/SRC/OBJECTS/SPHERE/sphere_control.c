/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:12:58 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:07:16 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void		set_sphere_radius(t_sphere *sphere, double radius)
{
	sphere->radius = radius;
}

void		set_sphere_pos(t_sphere *sphere, t_vec pos)
{
	vcopy(sphere->pos, pos);
}

void		set_sphere_color(t_sphere *sphere, t_vec color)
{
	vcopy(sphere->color, color);
}
