/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:42:10 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:51:12 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "db.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_plane
{
	int			id;
	t_vec		point;
	t_vec		normal;
	t_vec		color;
}				t_plane;

t_plane			*init_plane();
void			set_plane_point(t_plane *plane, t_vec point);
void			set_plane_normal(t_plane *plane, t_vec mormal);
void			set_plane_color(t_plane *plane, t_vec color);
void			collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter);
void			shadow_collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter);
#endif
