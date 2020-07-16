#include "cylinder.h"

t_circle		*make_circle(vec pos, vec normal, double radius, vec color)
{
    t_circle    *circle;

    if (!(circle = malloc(sizeof(t_circle))))
        return (NULL);
	vcopy(circle->pos, pos);
	vcopy(circle->normal, normal);
	circle->radius = radius;
	vcopy(circle->color, color);
	return (circle);
}

void			set_circle_pos(t_circle *circle, vec pos)
{
	vcopy(circle->pos, pos);
}

void			set_circle_normal(t_circle *circle, vec normal)
{
	vcopy(circle->normal, normal);
}

void			set_circle_radius(t_circle *circle, double radius)
{
	circle->radius = radius;
}

void			set_circle_color(t_circle *circle, vec color)
{
	vcopy(circle->color, color);
}

static double	equation(t_circle *circle, vec origin, vec dir)
{
	double t;

	if (vdot(circle->normal, dir) == 0)
		return (-1.);
	t = (vdot(circle->normal, circle->pos)
		- vdot(circle->normal, origin))
		/ vdot(circle->normal, dir);
	
	return (t);
}

static bool		check_inside(vec pos, t_circle *circle)
{
	vec	temp;

	vsubtract(temp, pos, circle->pos);
	if (vdot(temp, temp) < pow(circle->radius, 2))
		return (TRUE);
	return (FALSE);
}

static bool	collision(vec pos, t_circle *circle,
								vec origin, vec dir)
{
	double	t;

	t = equation(circle, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, circle))
		return (FALSE);
	return (TRUE);
}

void		collision_circle(t_circle *circle,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;

	if (collision(pos, circle, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, circle->normal))
			set_hitter_color(hitter, circle->color, circle->id);
}

void		shadow_collision_circle(t_circle *circle,
							t_ray *ray, t_hitter *hitter)
{
	vec temp;

	if (circle->id == hitter->obj_id)
		return;
	if (collision(temp, circle, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}