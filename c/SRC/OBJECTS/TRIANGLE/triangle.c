/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:19:35 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:08:50 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

t_triangle	*init_triangle(void)
{
	t_triangle *triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		error_exit("Malloc Error Occuered");
	triangle->id = -1;
	vmake(triangle->a, 1, 0, 0);
	vmake(triangle->b, 0, 1, 0);
	vmake(triangle->c, 0, 0, 1);
	vmake(triangle->color, 1, 0, 0);
	set_normal(triangle);
	return (triangle);
}
