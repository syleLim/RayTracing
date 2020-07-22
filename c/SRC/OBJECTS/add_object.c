/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:24:32 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:09:53 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	add_sphere(t_objs *objs, t_sphere *sphere)
{
	sphere->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->spheres[objs->sphere_num] = sphere;
	++objs->sphere_num;
}

void	add_plane(t_objs *objs, t_plane *plane)
{
	plane->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->planes[objs->plane_num] = plane;
	objs->plane_num++;
}

void	add_triangle(t_objs *objs, t_triangle *triangle)
{
	triangle->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->triangles[objs->triangle_num] = triangle;
	objs->triangle_num++;
}

void	add_square(t_objs *objs, t_square *square)
{
	square->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->squares[objs->square_num] = square;
	objs->square_num++;
}

void	add_cylinder(t_objs *objs, t_cylinder *cylinder)
{
	cylinder->id = objs->num_of_objs;
	cylinder->circles[0]->id = objs->num_of_objs;
	cylinder->circles[1]->id = objs->num_of_objs;
	++objs->num_of_objs;
	objs->cylinders[objs->cylinder_num] = cylinder;
	objs->cylinder_num++;
}
