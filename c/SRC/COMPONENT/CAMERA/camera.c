/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:21:56 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 08:58:03 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		error_exit("Malloc Error Occuered");
	vzero(camera->pos);
	vmake(camera->dir, -1, 0, 0);
	vmake(camera->up, 0, 0, 1);
	set_vwu(camera);
	camera->fov = INIT_FOV * PI / 180.;
	return (camera);
}
