/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:07:36 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:57:47 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vnormalize(t_vec v)
{
	double len;

	len = vlen(v);
	v[X] /= len;
	v[Y] /= len;
	v[Z] /= len;
}

void			vcross(t_vec dest, t_vec v1, t_vec v2)
{
	dest[X] = v1[Y] * v2[Z] - v1[Z] * v2[Y];
	dest[Y] = v1[Z] * v2[X] - v1[X] * v2[Z];
	dest[Z] = v1[X] * v2[Y] - v1[Y] * v2[X];
}

double			vlen(t_vec v)
{
	return (sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]));
}

double			vdot(t_vec v1, t_vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}
