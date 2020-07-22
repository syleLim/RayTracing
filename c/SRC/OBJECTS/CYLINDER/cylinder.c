/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:03:13 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:05:01 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_cylinder		*init_cylinder(void)
{
	t_cylinder	*cylinder;
	t_vec		neg_norm;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		error_exit("Malloc Error Occured");
	cylinder->id = -1;
	vzero(cylinder->pos);
	vmake(cylinder->normal, 0, 0, 1);
	vmake(neg_norm, 0, 0, -1);
	vmake(cylinder->color, 1, 1, 1);
	cylinder->diameter = 0.5;
	cylinder->height = 1.;
	set_p(cylinder);
	cylinder->circles[0] = make_circle(cylinder->p1, cylinder->normal,
								cylinder->diameter, cylinder->color);
	cylinder->circles[1] = make_circle(cylinder->p2, neg_norm,
								cylinder->diameter, cylinder->color);
	return (cylinder);
}
