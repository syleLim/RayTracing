#include "camera.h"

t_camera	*init_camera(vec pos, vec dir, double fov)
{
	t_camera	*camera;

	if(!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	camera->pos;
	camera->dir;
	camera->fov = fov * PI / 180.;
	return (camera);
}