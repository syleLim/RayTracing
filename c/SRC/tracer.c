#include "tracer.h"
#include "shadow.h"

void	clear_window(int *data, int width, int height)
{
	int i;

	i = -1;
	while (++i < width * height)
		data[i] = 0x000000;
}

void	tracing(t_objs *objs, t_components *comp, int camera_id)
{
	t_hitter	*hitter;
	t_ray		*ray;
	int 		i;
	int 		j;

	hitter = init_hitter();
	ray = init_ray();
	set_ray_origin(ray, comp->cameras[camera_id]->pos);
	i = -1;
	clear_window(comp->window->data,
		comp->window->width, comp->window->height);
	while (++i < comp->screens[camera_id]->height)
	{		
		j = -1;
		while (++j < comp->screens[camera_id]->width)
		{
			cal_ray_dir(ray, comp->screens[camera_id], i, j);
			objs_collision(objs, ray, hitter);
			if (hitter->is_hit)
			{
				comp->window->data[i * comp->window->width + j]
				= set_color(objs, comp, hitter, ray->origin);
			}
		}
	}
	mlx_put_image_to_window(comp->window->mlx,
		comp->window->window, comp->window->img, 0, 0);
	free(hitter);
	free(ray);
}