/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:39:42 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 08:41:07 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void		set_window(t_window *window, int width, int height)
{
	window->width = width;
	window->height = height;
	mlx_destroy_window(window->mlx, window->window);
	mlx_destroy_image(window->mlx, window->img);
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, width, height, "tester");
	window->img = mlx_new_image(window->mlx, width, height);
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
						&window->size_l, &window->endian);
}
