/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:46:11 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:12:09 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "db.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_sphere
{
	int			id;
	t_vec		pos;
	t_vec		color;
	double		radius;
}				t_sphere;

t_sphere		*init_sphere();
void			set_sphere_pos(t_sphere *sphere, t_vec pos);
void			set_sphere_radius(t_sphere *sphere, double radius);
void			set_sphere_color(t_sphere *sphere, t_vec color);
void			collision_sphere(t_sphere *sphere, t_ray *ray,
									t_hitter *hitter);
void			shadow_collision_sphere(t_sphere *sphere,
							t_ray *ray, t_hitter *hitter);
#endif
