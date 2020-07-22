/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:24:29 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 08:36:05 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		*init_light(void)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		error_exit("Malloc Error Occured");
	vzero(light->pos);
	vmake(light->color, 1, 1, 1);
	return (light);
}
