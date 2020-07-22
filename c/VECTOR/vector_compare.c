/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:08:55 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:15:10 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool			vcompare(t_vec v1, t_vec v2)
{
	if (v1[X] != v2[X] || v1[Y] != v2[Y] || v1[Z] != v2[Z])
		return (FALSE);
	return (TRUE);
}

t_bool			vcompare_neg(t_vec v1, t_vec v2)
{
	if (v1[X] != -v2[X] || v1[Y] != -v2[Y] || v1[Z] != -v2[Z])
		return (FALSE);
	return (TRUE);
}

double			vdiff(t_vec v1, t_vec v2)
{
	return (sqrt(pow(v1[X] - v2[X], 2)
				+ pow(v1[Y] - v2[Y], 2)
				+ pow(v1[Z] - v2[Z], 2)));
}
