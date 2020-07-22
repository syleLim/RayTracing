/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:37:10 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:17:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "db.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_circle
{
	int			id;
	t_vec		pos;
	t_vec		normal;
	double		radius;
	t_vec		color;
}				t_circle;

typedef struct	s_cylinder
{
	int			id;
	t_vec		pos;
	t_circle	*circles[2];
	t_vec		normal;
	t_vec		p1;
	t_vec		p2;
	double		diameter;
	double		height;
	t_vec		color;
}				t_cylinder;

t_circle		*make_circle(t_vec pos, t_vec normal,
							double radius, t_vec color);
void			set_circle_pos(t_circle *circle, t_vec pos);
void			set_circle_normal(t_circle *circle, t_vec normal);
void			set_circle_radius(t_circle *circle, double radius);
void			set_circle_color(t_circle *circle, t_vec color);
void			collision_circle(t_circle *circle,
						t_ray *ray, t_hitter *hitter);
void			shadow_collision_circle(t_circle *circle,
							t_ray *ray, t_hitter *hitter);
t_cylinder		*init_cylinder();
void			set_p(t_cylinder *cylinder);
void			set_cylinder_pos(t_cylinder *cylinder, t_vec pos);
void			set_cylinder_normal(t_cylinder *cylinder, t_vec normal);
void			set_cylinder_diameter(t_cylinder *cylinder, double diameter);
void			set_cylinder_height(t_cylinder *cylinder, double height);
void			set_cylinder_color(t_cylinder *cylinder, t_vec color);
t_bool			collision_eq_c(t_vec pos, t_cylinder *cylinder,
								t_vec origin, t_vec dir);
void			get_normal(t_vec normal, t_vec pos, t_cylinder *cylinder);
void			collision_cylinder(t_cylinder *cylinder,
						t_ray *ray, t_hitter *hitter);
void			shadow_collision_cylinder(t_cylinder *cylinder,
							t_ray *ray, t_hitter *hitter);

#endif
