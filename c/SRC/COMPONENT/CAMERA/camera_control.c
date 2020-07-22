/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:22:35 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:58:56 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void		set_vwu(t_camera *camera)
{
	vneg(camera->w, camera->dir);
	vcross(camera->u, camera->up, camera->w);
	vnormalize(camera->u);
	vcross(camera->v, camera->w, camera->u);
}

void		set_camera_pos(t_camera *camera, t_vec pos)
{
	vcopy(camera->pos, pos);
}

void		set_camera_fov(t_camera *camera, double fov)
{
	camera->fov = fov * PI / 180;
}

void		camera_rotate(t_camera *camera, t_vec orientaion)
{
	vrotate(camera->dir, camera->up, orientaion);
	vnormalize(camera->dir);
	vcopy(camera->up, orientaion);
	set_vwu(camera);
}
