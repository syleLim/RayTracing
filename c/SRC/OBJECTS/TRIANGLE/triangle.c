#include "triangle.h"

static void	set_normal(t_triangle *triangle)
{
	vec v1;
	vec v2;

	vsubtract(v1, triangle->a, triangle->b);
	vsubtract(v2, triangle->a, triangle->c);
	vcross(triangle->normal, v1, v2);
	vnormalize(triangle->normal);
}

t_triangle	*init_triangle()
{
	t_triangle *triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		return (NULL);
	triangle->id = -1;
	vmake(triangle->a, 1, 0, 0);
	vmake(triangle->b, 0, 1, 0);
	vmake(triangle->c, 0, 0, 1);
	vmake(triangle->color, 1, 0, 0);
	set_normal(triangle);
	return (triangle);
}

void		set_triangle_point_a(t_triangle *triangle, vec pos)
{
	vcopy(triangle->a, pos);
	set_normal(triangle);
}

void		set_triangle_point_b(t_triangle *triangle, vec pos)
{
	vcopy(triangle->b, pos);
	set_normal(triangle);
}

void		set_triangle_point_c(t_triangle *triangle, vec pos)
{
	vcopy(triangle->c, pos);
	set_normal(triangle);
}

void		set_triangle_color(t_triangle *triangle, vec color)
{
	vcopy(triangle->color, color);
}

static double	equation(t_triangle *triangle, vec origin, vec dir)
{
	double t;

	if (vdot(triangle->normal, dir) == 0)
		return (-1.);
	t = (vdot(triangle->normal, triangle->a)
		- vdot(triangle->normal, origin))
		/ vdot(triangle->normal, dir);
	
	return (t);
}

static bool		check_inside_2(vec normal, vec line[3], vec cone[3])
{
	vec cross[3];

	vcross(cross[0], line[0], cone[0]);
	vcross(cross[1], line[1], cone[1]);
	vcross(cross[2], line[2], cone[2]);
	if (vdot(normal, cross[0]) > 0 &&
		vdot(normal, cross[1]) > 0 &&
		vdot(normal, cross[2]) > 0)
		return (TRUE);
	return (FALSE);
}

static bool		check_inside(vec pos, t_triangle *triangle)
{
	vec line[3];
	vec cone[3];

	vsubtract(line[0], triangle->b, triangle->a);
	vsubtract(line[1], triangle->c, triangle->b);
	vsubtract(line[2], triangle->a, triangle->c);
	vsubtract(cone[0], pos, triangle->a);
	vsubtract(cone[1], pos, triangle->b);
	vsubtract(cone[2], pos, triangle->c);
	return (check_inside_2(triangle->normal, line, cone));
}	

static bool		collision(vec pos, t_triangle *triangle,
								vec origin, vec dir)
{
	double	t;

	t = equation(triangle, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, triangle))
		return (FALSE);
	return (TRUE);
}

void		collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;

	if (collision(pos, triangle, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, triangle->normal))
			set_hitter_color(hitter, triangle->color, triangle->id);
}

void		shadow_collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter)
{
	vec temp;

	if (triangle->id == hitter->obj_id)
		return;
	if (collision(temp, triangle, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}