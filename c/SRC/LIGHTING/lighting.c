#include "lighting.h"

static void	get_diffuse(vec diffuse, t_light *light,
						t_hitter *hitter)
{
	vec		pre;
	vec		l;
	double	a;

	vcopy(pre, light->color);
	vsubtract(l, light->pos, hitter->pos);
	vmultiple(light->color, light->color, 1 / vlen(l));
	vnormalize(l);
	a = fmax(vdot(l, hitter->normal), 0.);
	vmultiple(diffuse, light->color, a);
	vmultiply(diffuse, diffuse, hitter->color);
	vcopy(light->color, pre);
}

static void	get_specular(vec specular, t_light *light,
						t_hitter *hitter, vec origin)
{
	vec		pre;
	vec		l;
	vec		r;
	vec		v;
	double	a;

	vcopy(pre, light->color);
	vsubtract(l, light->pos, hitter->pos);
	vmultiple(light->color, light->color, 30 / vlen(l));
	vnormalize(l);
	vmultiple(specular, hitter->normal,
				2. * vdot(hitter->normal, l));
	vsubtract(r, specular, l);
	vsubtract(v, origin, hitter->pos);
	vnormalize(v);
	a = fmax(vdot(r, v), 0);
	vmultiple(specular, light->color, a);
	vmultiply(specular, specular, hitter->color);
	vcopy(light->color, pre);
}

static void	color_check(vec color)
{
	color[X] = color[X] > 1 ? 1 : color[X];
	color[Y] = color[Y] > 1 ? 1 : color[Y];
	color[Z] = color[Z] > 1 ? 1 : color[Z];
}

static int	color_vec_to_int(vec color)
{
	int r;
	int g;
	int b;

	r = (int)(color[X] * 255);
	g = (int)(color[Y] * 255);
	b = (int)(color[Z] * 255);
	return (r * 256 * 256 + g * 256 + b);
}

int			set_color(t_objs *objs, t_components *comp,
						t_hitter *hitter, vec origin)
{
	vec	diffuse;
	vec speculer;
	vec color;
	vec l;
	int i;
	
	vzero(color);
	i = -1;
	while (++i < comp->light_nums)
	{
		check_shadow(objs, hitter, comp->lights[i]);
		if (!hitter->is_shadow)
		{
			get_diffuse(diffuse, comp->lights[i], hitter);
			get_specular(speculer, comp->lights[i], hitter, origin);
			vadd(diffuse, diffuse, speculer);
			vadd(color, color, diffuse);
		}
		hitter->is_shadow = FALSE;
	}
	vadd(color, color, comp->ambient);
	color_check(color);
	return (color_vec_to_int(color));
}