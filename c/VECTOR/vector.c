/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:05:24 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:17:57 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vpoint(t_vec dest, t_vec origin, t_vec dir, double t)
{
	dest[X] = origin[X] + t * dir[X];
	dest[Y] = origin[Y] + t * dir[Y];
	dest[Z] = origin[Z] + t * dir[Z];
}
