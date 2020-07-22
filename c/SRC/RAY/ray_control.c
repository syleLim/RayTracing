/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:47:01 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:10:25 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	set_ray_origin(t_ray *ray, t_vec origin)
{
	vcopy(ray->origin, origin);
}

void	set_ray_dir(t_ray *ray, t_vec dir)
{
	vcopy(ray->dir, dir);
}

void	cal_ray_dir(t_ray *ray,
				t_screen *screen, double i, double j)
{
	double v;
	double u;

	v = i / (double)screen->height;
	u = j / (double)screen->width;
	ray->dir[X] = screen->origin[X]
		+ u * screen->horizontal[X] + v * screen->vertical[X] - ray->origin[X];
	ray->dir[Y] = screen->origin[Y]
		+ u * screen->horizontal[Y] + v * screen->vertical[Y] - ray->origin[Y];
	ray->dir[Z] = screen->origin[Z]
		+ u * screen->horizontal[Z] + v * screen->vertical[Z] - ray->origin[Z];
}
