/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:12:56 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:06:23 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	*init_sphere(void)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		error_exit("Malloc Error Occuered");
	sphere->id = -1;
	sphere->radius = 1;
	vzero(sphere->pos);
	vmake(sphere->color, 1, 1, 1);
	return (sphere);
}
