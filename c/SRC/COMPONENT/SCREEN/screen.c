/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:36:39 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:59:11 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

t_screen	*init_screen(t_camera *camera, int w, int h)
{
	t_screen	*screen;

	if (!(screen = malloc(sizeof(t_screen))))
		error_exit("Malloc Error Occured");
	screen->width = w;
	screen->height = h;
	set_screen_vector(screen, camera);
	return (screen);
}
