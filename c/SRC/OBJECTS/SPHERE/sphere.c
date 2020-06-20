#include "sphere.h"

t_sphere	*init_sphere()
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->radius = 1;
	vzero(sphere->pos);
	vmake(sphere->color, 1, 1, 1);
}

void		set_sphere_radius(t_sphere *sphere, double radius)
{
	sphere->radius = radius;
}

void		set_sphere_pos(t_sphere *sphere, vec pos)
{
	vcopy(sphere->pos, pos);
}

void		set_sphere_color(t_sphere *sphere, vec color)
{
	vcopy(sphere->color, color);
}

static double	equation(t_sphere *sphere,
						vec origin, vec dir)
{
	vec oc;
	double a;
	double b;
	double c;
	double discriminant;

	vsubtract(oc, origin, sphere->pos);
	a = vdot(dir, dir);
	b = vdot(oc, dir);
	c = vdot(oc, oc) - pow(sphere->radius, 2);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	if ((-b - sqrt(b * b - a * c)) / a > 0)
		return ((-b - sqrt(b * b - a * c)) / a);
	if ((-b + sqrt(b * b - a * c)) / a > 0)
		return ((-b + sqrt(b * b - a * c)) / a);
	return (-1);
}

static bool	collision(vec pos, t_sphere *sphere,
						vec origin, vec dir)
{
	double t;

	t = equation(sphere, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	return (TRUE);
}

void		collision_sphere(t_sphere *sphere, t_ray *ray,
								 t_hitter *hitter)
{
	vec pos;
	vec normal;

	if (collision(pos, sphere, ray->origin, ray->dir))
	{
		vsubtract(normal, pos, sphere->pos);
		check_hitter(hitter, pos, ray->origin, normal);
	}
}