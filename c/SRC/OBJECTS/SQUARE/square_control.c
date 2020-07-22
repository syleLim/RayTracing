/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:16:02 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:08:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

void		set_abcd(t_square *square, double size, t_vec normal)
{
	t_vec		up;

	vmake(up, 0, 0, 1);
	vmake(square->a, size / 2., size / 2., 0);
	vmake(square->b, -size / 2., size / 2., 0);
	vmake(square->c, size / 2., -size / 2., 0);
	vmake(square->d, -size / 2., -size / 2., 0);
	vrotate(square->a, up, normal);
	vrotate(square->b, up, normal);
	vrotate(square->c, up, normal);
	vrotate(square->d, up, normal);
}

void		set_square_normal(t_square *square, t_vec normal)
{
	set_abcd(square, square->size, normal);
	vcopy(square->normal, normal);
}

void		set_square_pos(t_square *square, t_vec pos)
{
	vcopy(square->pos, pos);
}

void		set_square_size(t_square *square, double size)
{
	set_abcd(square, size, square->normal);
	square->size = size;
}

void		set_square_color(t_square *square, t_vec color)
{
	vcopy(square->color, color);
}
