#ifndef CAMERA_H
# define CAMERA_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef	struct	s_camera
{
	vec			pos;
	vec			dir;
	vec			up;
	vec			v;
	vec			u;
	vec			w;
	vec			orientaion;
	double		fov;
}				t_camera;

t_camera	*init_camera();
void		set_camera_pos(t_camera *camera, vec pos);
void		set_camera_fov(t_camera *camera, double fov);
void		camera_rotate(t_camera *camera, vec orientaion);

#endif