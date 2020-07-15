#include "vector.h"

void    qmake(quaternion q, double xyz[3], double w)
{
    q[X] = xyz[X];
    q[Y] = xyz[Y];
    q[Z] = xyz[Z];
    q[W] = w;
}

void	qorthogonal(quaternion q, double u[3])
{
	vec		cross;
	vec		other;
	double	x;
	double	y;
	double	z;

	x = fabs(u[X]);
	y = fabs(u[Y]);
	z = fabs(u[Z]);
	x < y ? (x < z ? vmake(other, 1, 0, 0) : vmake(other, 0, 0, 1)) :
		(y < z ? vmake(other, 0, 1, 0) : vmake(other, 0, 0, 1));
	vcross(cross, u, other);
	qmake(q, cross, 0);
}

void    qrotate(double v[3], quaternion q)
{
    vec rot[3];
	vec temp;
			
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