#include "tracer.h"

void	tracing(t_objs *objs, t_light *light,
					t_hitter *hitter, t_ray *ray,
					t_camera *camera, t_screen *screen)
{
	vec color;
	int i;
	int j;

	i = -1;
	while (++i < screen->height)
	{
		j = -1;
		while (++j < screen->width)
		{
			cal_ray_dir(ray, screen,
					(double)i / (double)screen->height,
					(double)j / (double)screen->width);
			objs_collision(objs, ray, hitter);
			if (hitter->is_hit)
				set_color(color, light, hitter, ray->origin);
			//TODO : set color in screen
		}
	}
}