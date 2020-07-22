/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:41:24 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:59:32 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "components.h"

t_components	*init_components(void)
{
	t_components	*comp;

	if (!(comp = malloc(sizeof(t_components))))
		error_exit("Malloc Error Occured");
	comp->window = init_window();
	comp->cameras[0] = init_camera();
	comp->camera_nums = 0;
	comp->screens[0] = init_screen(
				comp->cameras[0], comp->window->width, comp->window->height);
	comp->screen_nums = 0;
	comp->lights[0] = init_light();
	comp->light_nums = 0;
	vmake(comp->ambient, 0.01, 0.01, 0.01);
	return (comp);
}
