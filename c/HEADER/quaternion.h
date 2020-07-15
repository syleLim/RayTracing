#ifndef QUATERNION_H
# define QUATERNION_H
typedef double quaternion[4];

void    qmake(quaternion q, double xyz[3], double w);
void	qorthogonal(quaternion q, double u[3]);
void    qrotate(double v[3], quaternion q);
#endif