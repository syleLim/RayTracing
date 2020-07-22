/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:10:06 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:05:47 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_plane		*init_plane(void)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		error_exit("Malloc Error Ouccered");
	plane->id = -1;
	vzero(plane->point);
	vmake(plane->normal, 0, 0, 1);
	vmake(plane->color, 1, 1, 1);
	return (plane);
}
