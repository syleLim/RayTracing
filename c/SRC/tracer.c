/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:58:44 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:10:48 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

void		clear_window(int *data, int width, int height)
{
	int i;

	i = -1;
	while (++i < width * height)
		data[i] = 0x000000;
}

static void	init_tracing(t_hitter **hitter, t_ray **ray,
							t_components *comp, int camera_id)
{
	*hitter = init_hitter();
	*ray = init_ray();
	set_ray_origin(*ray, comp->cameras[camera_id]->pos);
	clear_window(comp->window->data,
		comp->window->width, comp->window->height);
}

void		tracing(t_objs *objs, t_components *comp, int camera_id)
{
	t_hitter	*hitter;
	t_ray		*ray;
	int			i;
	int			j;

	init_tracing(&hitter, &ray, comp, camera_id);
	i = -1;
	while (++i < comp->screens[camera_id]->height)
	{
		j = -1;
		while (++j < comp->screens[camera_id]->width)
		{
			cal_ray_dir(ray, comp->screens[camera_id], i, j);
			objs_collision(objs, ray, hitter);
			if (hitter->is_hit)
			{
				comp->window->data[i * comp->window->width + j] =
				set_color(objs, comp, hitter, ray->origin);
			}
		}
	}
	mlx_put_image_to_window(comp->window->mlx,
		comp->window->window, comp->window->img, 0, 0);
	free(hitter);
	free(ray);
}
