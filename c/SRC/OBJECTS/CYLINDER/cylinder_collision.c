/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:03:44 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:04:40 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void			collision_cylinder(t_cylinder *cylinder,
						t_ray *ray, t_hitter *hitter)
{
	t_vec	pos;
	t_vec	normal;
	int		i;

	i = -1;
	while (++i < 2)
		collision_circle(cylinder->circles[i], ray, hitter);
	if (collision_eq_c(pos, cylinder, ray->origin, ray->dir))
	{
		get_normal(normal, pos, cylinder);
		if (check_hitter(hitter, pos, ray->origin, normal))
			set_hitter_color(hitter, cylinder->color, cylinder->id);
	}
}

void			shadow_collision_cylinder(t_cylinder *cylinder,
							t_ray *ray, t_hitter *hitter)
{
	t_vec	temp;
	int		i;

	if (cylinder->id == hitter->obj_id)
		return ;
	i = -1;
	while (++i < 2)
		shadow_collision_circle(cylinder->circles[i], ray, hitter);
	if (collision_eq_c(temp, cylinder, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
