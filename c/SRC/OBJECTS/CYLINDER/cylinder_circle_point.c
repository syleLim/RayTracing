/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_circle_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:01:58 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:02:56 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void		set_p(t_cylinder *cylinder)
{
	t_vec		temp;

	vmultiple(temp, cylinder->normal,
		cylinder->height / (vlen(cylinder->normal) * 2));
	vadd(cylinder->p1, cylinder->pos, temp);
	vneg(temp, temp);
	vadd(cylinder->p2, cylinder->pos, temp);
}
