/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:40:35 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:40:54 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "sphere.h"
# include "plane.h"
# include "triangle.h"
# include "square.h"
# include "cylinder.h"

typedef struct	s_objs
{
	int			num_of_objs;
	int			sphere_num;
	int			plane_num;
	int			triangle_num;
	int			square_num;
	int			cylinder_num;
	t_sphere	*spheres[MAXOBJECT];
	t_plane		*planes[MAXOBJECT];
	t_triangle	*triangles[MAXOBJECT];
	t_square	*squares[MAXOBJECT];
	t_cylinder	*cylinders[MAXOBJECT];
}				t_objs;

t_objs			*init_objs();
void			add_sphere(t_objs *objs, t_sphere *sphere);
void			add_plane(t_objs *objs, t_plane *plane);
void			add_triangle(t_objs *objs, t_triangle *triangle);
void			add_square(t_objs *objs, t_square *square);
void			add_cylinder(t_objs *objs, t_cylinder *cylinder);
void			objs_collision(t_objs *objs, t_ray *ray, t_hitter *hitter);

#endif
