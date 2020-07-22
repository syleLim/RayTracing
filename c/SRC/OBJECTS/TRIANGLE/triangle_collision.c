/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:20:38 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:08:47 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

void			collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter)
{
	t_vec pos;

	if (collision_eq_t(pos, triangle, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, triangle->normal))
			set_hitter_color(hitter, triangle->color, triangle->id);
}

void			shadow_collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter)
{
	t_vec temp;

	if (triangle->id == hitter->obj_id)
		return ;
	if (collision_eq_t(temp, triangle, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
