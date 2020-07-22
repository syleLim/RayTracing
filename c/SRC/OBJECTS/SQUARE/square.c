/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:15:44 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:07:43 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

t_square		*init_square(void)
{
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		error_exit("Malloc Error Occured");
	square->id = -1;
	vzero(square->pos);
	vmake(square->normal, 0, 0, 1);
	vmake(square->color, 1, 1, 1);
	square->size = 1.;
	set_abcd(square, square->size, square->normal);
	return (square);
}
