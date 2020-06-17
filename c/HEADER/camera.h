#ifndef CAMERA_H
# define CAMERA_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef	struct	s_camera
{
	vec			pos;
	vec			dir;
	double		fov;
}				t_camera;

#endif