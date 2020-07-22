/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:05:49 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:57:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vzero(t_vec v)
{
	v[X] = 0;
	v[Y] = 0;
	v[Z] = 0;
}

void			vcopy(t_vec dest, t_vec src)
{
	dest[X] = src[X];
	dest[Y] = src[Y];
	dest[Z] = src[Z];
}

void			vmake(t_vec dest, double x, double y, double z)
{
	dest[X] = x;
	dest[Y] = y;
	dest[Z] = z;
}
