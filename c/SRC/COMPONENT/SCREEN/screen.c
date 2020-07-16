#include "screen.h"

static void	set_origin(vec origin, double w, double h,
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
	h = w * (double)screen->height / (double)screen-> width;
	set_origin(screen->origin, w, h, camera);
	vmultiple(screen->horizontal, camera->u, 2. * w);
	vmultiple(screen->vertical, camera->v, 2. * h);
}

t_screen	*init_screen(t_camera *camera, int w, int h)
{
	t_screen	*screen;

	if (!(screen = malloc(sizeof(t_screen))))
		return (NULL);
	screen->width = w;
	screen->height = h;
	set_screen_vector(screen, camera);
	return (screen);
}

void		set_screen_wh(t_screen *screen,
						int width, int height)
{
	screen->width = width;
	screen->height = height;
}

