#include "sphere.h"

t_sphere	*init_sphere()
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->id = -1;
	sphere->radius = 1;
	vzero(sphere->pos);
	vmake(sphere->color, 1, 1, 1);
	return (sphere);
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
	if ((-b - sqrt(discriminant)) / a > 0)
		return ((-b - sqrt(discriminant)) / a);
	if ((-b + sqrt(discriminant)) / a > 0)
		return ((-b + sqrt(discriminant)) / a);
	return (-1);
}

static bool	collision(vec pos, t_sphere *sphere,
						vec origin, vec dir)
{
	double t;

	t = equation(sphere, origin, dir);
	//printf("t : %.3f\n", t);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	return (TRUE);
}

void		collision_sphere(t_sphere *sphere,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;
	vec normal;

	if (collision(pos, sphere, ray->origin, ray->dir))
	{
		vsubtract(normal, pos, sphere->pos);
		vnormalize(normal);
		if (check_hitter(hitter, pos, ray->origin, normal))
			set_hitter_color(hitter, sphere->color, sphere->id);
	}
}

void		shadow_collision_sphere(t_sphere *sphere,
							t_ray *ray, t_hitter *hitter)
{
	vec temp;

	if (sphere->id == hitter->obj_id)
		return;
	if (collision(temp, sphere, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}