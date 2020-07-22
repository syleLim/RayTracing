/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:35:03 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:12:31 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <stdlib.h>
# include "db.h"
# include "vector.h"
# include "error.h"

typedef	struct	s_camera
{
	t_vec		pos;
	t_vec		dir;
	t_vec		up;
	t_vec		v;
	t_vec		u;
	t_vec		w;
	double		fov;
}				t_camera;

t_camera		*init_camera();
void			set_vwu(t_camera *camera);
void			set_camera_pos(t_camera *camera, t_vec pos);
void			set_camera_fov(t_camera *camera, double fov);
void			camera_rotate(t_camera *camera, t_vec orientaion);

#endif
