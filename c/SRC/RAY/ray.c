/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:46:33 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:10:19 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		error_exit("Malloc Error Occured");
	vzero(ray->origin);
	vzero(ray->dir);
	return (ray);
}
