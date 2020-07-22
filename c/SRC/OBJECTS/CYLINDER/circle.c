/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:54:09 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:04:53 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_circle		*make_circle(t_vec pos, t_vec normal,
							double radius, t_vec color)
{
	t_circle	*circle;

	if (!(circle = malloc(sizeof(t_circle))))
		error_exit("Malloc Error Occured");
	vcopy(circle->pos, pos);
	vcopy(circle->normal, normal);
	circle->radius = radius;
	vcopy(circle->color, color);
	return (circle);
}
