/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:08:26 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:29:57 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vrotate(t_vec v, t_vec u, t_vec ori)
{
	t_vec			half;
	t_vec			cross;
	t_quaternion	q;

	vnormalize(u);
	vnormalize(ori);
	if (vcompare(u, ori))
		return ;
	if (vcompare_neg(u, ori))
		qorthogonal(q, u);
	vcross(cross, u, ori);
	vnormalize(cross);
	if (vcompare(v, cross) || vcompare_neg(v, cross))
		return ;
	else
	{
		vadd(half, u, ori);
		vnormalize(half);
		vcross(cross, u, half);
		qmake(q, cross, vdot(u, half));
	}
	qrotate(v, q);
}
