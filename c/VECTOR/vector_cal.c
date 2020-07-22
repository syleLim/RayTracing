/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:07:05 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:56:57 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vneg(t_vec dest, t_vec src)
{
	dest[X] = -src[X];
	dest[Y] = -src[Y];
	dest[Z] = -src[Z];
}

void			vmultiple(t_vec dest, t_vec src, double value)
{
	dest[X] = src[X] * value;
	dest[Y] = src[Y] * value;
	dest[Z] = src[Z] * value;
}

void			vmultiply(t_vec dest, t_vec v1, t_vec v2)
{
	dest[X] = v1[X] * v2[X];
	dest[Y] = v1[Y] * v2[Y];
	dest[Z] = v1[Z] * v2[Z];
}

void			vsubtract(t_vec dest, t_vec v1, t_vec v2)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
}

void			vadd(t_vec dest, t_vec v1, t_vec v2)
{
	dest[X] = v1[X] + v2[X];
	dest[Y] = v1[Y] + v2[Y];
	dest[Z] = v1[Z] + v2[Z];
}
