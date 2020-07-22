/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:13:46 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:07:01 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

static double	equation(t_sphere *sphere,
						t_vec origin, t_vec dir)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	vsubtract(oc, origin, sphere->pos);
	a = vdot(dir, dir);
	b = vdot(oc, dir);
	c = vdot(oc, oc) - pow(sphere->radius, 2);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	if ((-b - sqrt(discriminant)) / a > 0)
		return ((-b - sqrt(discriminant)) / a);
	if ((-b + sqrt(discriminant)) / a > 0)
		return ((-b + sqrt(discriminant)) / a);
	return (-1);
}

static t_bool	collision(t_vec pos, t_sphere *sphere,
						t_vec origin, t_vec dir)
{
	double t;

	t = equation(sphere, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	return (TRUE);
}

void			collision_sphere(t_sphere *sphere,
						t_ray *ray, t_hitter *hitter)
{
	t_vec pos;
	t_vec normal;

	if (collision(pos, sphere, ray->origin, ray->dir))
	{
		vsubtract(normal, pos, sphere->pos);
		vnormalize(normal);
		if (check_hitter(hitter, pos, ray->origin, normal))
			set_hitter_color(hitter, sphere->color, sphere->id);
	}
}

void			shadow_collision_sphere(t_sphere *sphere,
							t_ray *ray, t_hitter *hitter)
{
	t_vec temp;

	if (sphere->id == hitter->obj_id)
		return ;
	if (collision(temp, sphere, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
