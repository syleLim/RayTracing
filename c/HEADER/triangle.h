/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:48:02 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:09:36 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H
# include "db.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_triangle
{
	int			id;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_vec		normal;
	t_vec		color;
}				t_triangle;

t_triangle		*init_triangle();
void			set_normal(t_triangle *triangle);
void			set_triangle_point_a(t_triangle *triangle, t_vec pos);
void			set_triangle_point_b(t_triangle *triangle, t_vec pos);
void			set_triangle_point_c(t_triangle *triangle, t_vec pos);
void			set_triangle_color(t_triangle *triangle, t_vec color);
t_bool			collision_eq_t(t_vec pos, t_triangle *triangle,
								t_vec origin, t_vec dir);
void			collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter);
void			shadow_collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter);
#endif
