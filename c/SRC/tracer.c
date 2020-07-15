#include "tracer.h"
#include "shadow.h"

int		coloring(vec color)
{
	int r;
	int g;
	int b;

	r = (int)(color[X] * 255);
	g = (int)(color[Y] * 255);
	b = (int)(color[Z] * 255);
	return (r * 256 * 256 + g * 256 + b);
}

void	tracing(t_objs *objs, t_light *light,
					t_screen *screen, t_window *window)
{
	t_hitter	*hitter;
	t_ray		*ray;
	vec			color;
	int 		i;
	int 		j;

	hitter = init_hitter();
	ray = init_ray();
	i = -1;
	while (++i < screen->height)
	{		
		j = -1;
		while (++j < screen->width)
		{
			cal_ray_dir(ray, screen, i, j);
			objs_collision(objs, ray, hitter);
			if (hitter->is_hit)
			{
				check_shadow(objs, hitter, light);
				set_color(color, light, hitter, ray->origin);
				window->data[i * window->width + j] = coloring(color);
			}
		}
	}
	mlx_put_image_to_window(window->mlx, window->window,
								window->img, 0, 0);
	free(hitter);
	free(ray);
}