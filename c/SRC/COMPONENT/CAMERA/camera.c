#include "camera.h"

static void	set_vwu(t_camera *camera)
{
	vneg(camera->w, camera->dir);
	vcross(camera->u, camera->up, camera->w);
	vnormalize(camera->u);
	vcross(camera->v, camera->w, camera->u);
	vnormalize(camera->v);
}

t_camera	*init_camera()
{
	t_camera	*camera;

	if(!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	vzero(camera->pos);
	vmake(camera->dir, -1, 0, 0);
	vmake(camera->up, 0, 0, 1);
	set_vwu(camera);
	camera->fov = INIT_FOV * PI / 180.;
	return (camera);	
}

void		set_camera_pos(t_camera *camera, vec pos)
{
	vcopy(camera->pos, pos);
}

void		set_camera_fov(t_camera *camera, double fov)
{
	camera->fov = fov * PI / 180;
}

void		camera_rotate(t_camera *camera, vec orientaion)
{
	vrotate(camera->dir, camera->up, orientaion);
	vnormalize(camera->dir);
	vrotate(camera->w, camera->up, orientaion);
	vnormalize(camera->w);
	vrotate(camera->v, camera->up, orientaion);
	vnormalize(camera->v);
	vrotate(camera->u, camera->up, orientaion);
	vnormalize(camera->u);
	vcopy(camera->up, orientaion);
}

