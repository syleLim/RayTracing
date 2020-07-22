/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:38:49 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 08:42:55 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

t_window	*init_window(void)
{
	t_window	*window;

	if (!(window = malloc(sizeof(t_window))))
		error_exit("Malloc Error Occured");
	window->width = 640;
	window->height = 480;
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, 640, 480, "tester");
	window->img = mlx_new_image(window->mlx, 640, 480);
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
											&window->size_l, &window->endian);
	return (window);
}
