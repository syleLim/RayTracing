/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:05:17 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:58:29 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	qmake(t_quaternion q, double xyz[3], double w)
{
	q[X] = xyz[X];
	q[Y] = xyz[Y];
	q[Z] = xyz[Z];
	q[W] = w;
}

void	qorthogonal(t_quaternion q, double u[3])
{
	t_vec		cross;
	t_vec		other;
	double		x;
	double		y;
	double		z;

	x = fabs(u[X]);
	y = fabs(u[Y]);
	z = fabs(u[Z]);
	if (x < y)
		x < z ? vmake(other, 1, 0, 0) : vmake(other, 0, 0, 1);
	else
		y < z ? vmake(other, 0, 1, 0) : vmake(other, 0, 0, 1);
	vcross(cross, u, other);
	qmake(q, cross, 0);
}

void	qrotate(double v[3], t_quaternion q)
{
	t_vec rot[3];
	t_vec temp;

	vmake(rot[0], q[X] * q[X] + q[Y] * q[Y] - q[Z] * q[Z] - q[W] * q[W],
			2 * (q[Y] * q[Z] - q[X] * q[W]),
			2 * (q[X] * q[Z] + q[Y] * q[W]));
	vmake(rot[1], 2 * (q[X] * q[W] + q[Y] * q[Z]),
			q[X] * q[X] - q[Y] * q[Y] + q[Z] * q[Z] - q[W] * q[W],
			2 * (q[Z] * q[W] - q[X] * q[Y]));
	vmake(rot[2], 2 * (q[Y] * q[W] - q[Y] * q[Z]),
			2 * (q[X] * q[Y] - q[Z] * q[W]),
			q[X] * q[X] - q[Y] * q[Y] - q[Z] * q[Z] + q[W] * q[W]);
	temp[X] = vdot(v, rot[0]);
	temp[Y] = vdot(v, rot[1]);
	temp[Z] = vdot(v, rot[2]);
	vcopy(v, temp);
}
