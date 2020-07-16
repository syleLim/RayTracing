#include "cylinder.h"

static void		set_p(t_cylinder *cylinder)
{
	vec		temp;

	vmultiple(temp, cylinder->normal,
		cylinder->height / (vlen(cylinder->normal) * 2));
	vadd(cylinder->p1, cylinder->pos, temp);
	vneg(temp, temp);
	vadd(cylinder->p2, cylinder->pos, temp);
}

t_cylinder		*init_cylinder()
{
	t_cylinder	*cylinder;
	vec			neg_norm;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->id = -1;
	vzero(cylinder->pos);
	vmake(cylinder->normal, 0, 0, 1);
	vmake(neg_norm, 0, 0, -1);
	vmake(cylinder->color, 1, 1, 1);
	cylinder->diameter = 0.5;
	cylinder->height = 1.;
	set_p(cylinder);
	cylinder->circles[0] = make_circle(cylinder->p1, cylinder->normal,
								cylinder->diameter, cylinder->color);
	cylinder->circles[1] = make_circle(cylinder->p2, neg_norm,
								cylinder->diameter, cylinder->color);
	return (cylinder);
}

void			set_cylinder_pos(t_cylinder *cylinder, vec pos)
{
	vcopy(cylinder->pos, pos);
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
}

void			set_cylinder_normal(t_cylinder *cylinder, vec normal)
{
	vec neg_norm;

	vneg(neg_norm, normal);
	vcopy(cylinder->normal, normal);
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
	set_circle_normal(cylinder->circles[0], cylinder->normal);
	set_circle_normal(cylinder->circles[1], neg_norm);
}

void			set_cylinder_diameter(t_cylinder *cylinder, double diameter)
{
	cylinder->diameter = diameter;
	set_circle_radius(cylinder->circles[0], diameter);
	set_circle_radius(cylinder->circles[1], diameter);
}

void			set_cylinder_color(t_cylinder *cylinder, vec color)
{
	vcopy(cylinder->color, color);
	set_circle_color(cylinder->circles[0], color);
	set_circle_color(cylinder->circles[1], color);
}

void			set_cylinder_height(t_cylinder *cylinder, double height)
{
	cylinder->height = height;
	set_p(cylinder);
	set_circle_pos(cylinder->circles[0], cylinder->p1);
	set_circle_pos(cylinder->circles[1], cylinder->p2);
}

static void		set_xy(vec xy[2], t_cylinder *cylinder, vec origin, vec dir)
{
	vec		m;
	vec		v;
	double	n;
	double	l;
	double	k;

	vsubtract(v, cylinder->p2, cylinder->p1);
	vsubtract(m, origin, cylinder->p1);
	n = vdot(origin, v) -  vdot(cylinder->p1, v);
	l = vdot(v, v);
	k = vdot(v, dir);
	vmultiple(xy[X], v, k / l);
	vsubtract(xy[X], dir, xy[X]);
	vmultiple(xy[Y], v, n / l);
	vsubtract(xy[Y], m, xy[Y]);
}

static double	equation(t_cylinder *cylinder, vec origin, vec dir, vec xy[2])
{
	double t;
	double a;
	double b;
	double c;
	double discriminant;

	a = vdot(xy[X], xy[X]);
	b = vdot(xy[X], xy[Y]);
	c = vdot(xy[Y], xy[Y]) - pow(cylinder->diameter, 2);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	if ((-b - sqrt(discriminant)) / a > 0)
		return ((-b - sqrt(discriminant)) / a);
	if ((-b + sqrt(discriminant)) / a > 0)
		return ((-b + sqrt(discriminant)) / a);
	return (-1);
	
	
	return (t);
}

static bool		check_inside(double t, t_cylinder *cylinder, vec origin, vec dir)
{
	vec		v;
	double	checker;

	vsubtract(v, cylinder->p2, cylinder->p1);
	checker = (vdot(origin, v) + t * vdot(dir, v) - vdot(cylinder->p1, v))
						/ vdot(v, v);
	return ((0 <= checker && checker <= 1));
}

static bool		collision(vec pos, t_cylinder *cylinder,
								vec origin, vec dir)
{
	vec		xy[2];
	double	t;

	set_xy(xy, cylinder, origin, dir);
	t = equation(cylinder, origin, dir, xy);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(t, cylinder, origin, dir))
		return (FALSE);
	return (TRUE);
}

static void		get_normal(vec normal, vec pos, t_cylinder *cylinder)
{
	vec		v;
	vec		temp;
	double	a;

	vsubtract(v, cylinder->p2, cylinder->p1);
	a = (vdot(pos, v) - vdot(cylinder->p1, v)) / vdot(v, v);
	vmultiple(temp, v, a);
	vadd(temp, temp, cylinder->p1);
	vsubtract(normal, pos, temp);
	vnormalize(normal);
}

void			collision_cylinder(t_cylinder *cylinder,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;
	vec normal;
	int i;

	i = -1;
	while (++i < 2)
		collision_circle(cylinder->circles[i], ray, hitter);
	if (collision(pos, cylinder, ray->origin, ray->dir))
	{
		get_normal(normal, pos, cylinder);
		if (check_hitter(hitter, pos, ray->origin, normal))
			set_hitter_color(hitter, cylinder->color, cylinder->id);
	}
}

void			shadow_collision_cylinder(t_cylinder *cylinder,
							t_ray *ray, t_hitter *hitter)
{
	vec temp;
	int	i;

	if (cylinder->id == hitter->obj_id)
		return;
	i = -1;
	while (++i < 2)
		shadow_collision_circle(cylinder->circles[i], ray, hitter);
	if (collision(temp, cylinder, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}
