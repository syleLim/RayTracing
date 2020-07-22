/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:37:07 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:59:26 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

static void	set_origin(t_vec origin, double w, double h,
						t_camera *camera)
{
	origin[X] = camera->pos[X] - w * camera->u[X]
				- h * camera->v[X] - camera->w[X];
	origin[Y] = camera->pos[Y] - w * camera->u[Y]
				- h * camera->v[Y] - camera->w[Y];
	origin[Z] = camera->pos[Z] - w * camera->u[Z]
				- h * camera->v[Z] - camera->w[Z];
}

void		set_screen_vector(t_screen *screen, t_camera *camera)
{
	double	w;
	double	h;

	w = tan(camera->fov / 2);
	h = w * (double)screen->height / (double)screen->width;
	set_origin(screen->origin, w, h, camera);
	vmultiple(screen->horizontal, camera->u, 2. * w);
	vmultiple(screen->vertical, camera->v, 2. * h);
}

void		set_screen_wh(t_screen *screen,
						int width, int height)
{
	screen->width = width;
	screen->height = height;
}
