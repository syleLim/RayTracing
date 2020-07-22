/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:11:02 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:06:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void		set_plane_point(t_plane *plane, t_vec point)
{
	vcopy(plane->point, point);
}

void		set_plane_normal(t_plane *plane, t_vec normal)
{
	vcopy(plane->normal, normal);
}

void		set_plane_color(t_plane *plane, t_vec color)
{
	vcopy(plane->color, color);
}
