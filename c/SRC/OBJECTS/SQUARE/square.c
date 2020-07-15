#include "square.h"

static void     set_abcd(t_square *square, double size, vec normal)
{
	vec		up;

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

t_square		*init_square()
{
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		return (NULL);
	square->id = -1;
	vzero(square->pos);
	vmake(square->normal, 0, 0, 1);
	vmake(square->color, 1, 1, 1);
	square->size = 1.;
	set_abcd(square, square->size, square->normal);
	return (square);
}

void			set_square_normal(t_square *square, vec normal)
{
	set_abcd(square, square->size, normal);
	vcopy(square->normal, normal);
}

void			set_square_pos(t_square *square, vec pos)
{
	vcopy(square->pos, pos);
}

void			set_square_size(t_square *square, double size)
{
	set_abcd(square, size, square->normal);
	square->size = size;
}

void			set_square_color(t_square *square, vec color)
{
	vcopy(square->color, color);
}

static double	equation(t_square *square, vec origin, vec dir)
{
	double t;

	if (vdot(square->normal, dir) == 0)
		return (-1.);
	t = (vdot(square->normal, square->pos)
		- vdot(square->normal, origin))
		/ vdot(square->normal, dir);
	
	return (t);
}

static bool		check_inside(vec pos, t_square *square)
{
	vec		ab;
	vec		ac;
	vec		ap;
	double	sol[2];

	vsubtract(ab, square->b, square->a);
	vsubtract(ac, square->c, square->a);
	vadd(ap, square->pos, square->a);
	vsubtract(ap, pos, ap);
	sol[0] = vdot(ap, ab) / vdot(ab, ab);
	sol[1] = vdot(ap, ac) / vdot(ac, ac);
	if (0. < sol[0] && sol[0] < 1. && 0. < sol[1] && sol[1] < 1.)
		return (TRUE);
	return (FALSE);
}

static bool		collision(vec pos, t_square *square,
								vec origin, vec dir)
{
	double	t;

	t = equation(square, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	if (!check_inside(pos, square))
		return (FALSE);
	return (TRUE);
}

void		collision_square(t_square *square,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;

	if (collision(pos, square, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, square->normal))
			set_hitter_color(hitter, square->color, square->id);
}

void		shadow_collision_square(t_square *square,
							t_ray *ray, t_hitter *hitter)
{
	vec temp;

	if (square->id == hitter->obj_id)
		return;
	if (collision(temp, square, ray->origin, ray->dir))
		hitter->is_hit = TRUE;
}