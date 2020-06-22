#include "light.h"

t_light		*init_light()
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	vzero(light->pos);
	vmake(light->color, 1, 1, 1);
	vzero(light->ambient);
	light->intensity = 1.;
	return (light);	
}

void		set_light_color(t_light *light, vec color)
{
	vcopy(light->color, color);
}

void		set_light_pos(t_light *light, vec pos)
{
	vcopy(light->pos, pos);
}

void		set_light_intensity(t_light *light, double intensity)
{
	light->intensity = intensity;
}

void		set_light_ambient(t_light *light, vec ambient)
{
	vcopy(light->ambient, ambient);
}

static void	get_diffuse(vec diffuse, t_light *light,
						t_hitter *hitter)
{
	vec		temp;
	vec		l;
	double	a;

	vsubtract(l, light->pos, hitter->pos);
	vnormalize(l);
	a = fmax(vdot(l, hitter->normal), 0.);
	vmultiple(temp, light->color, a);
	vmultiply(diffuse, temp, hitter->color);
}

static void	get_specular(vec specular, t_light *light,
						t_hitter *hitter, vec origin)
{
	vec		l;
	vec		r;
	vec		v;
	vec		temp;
	double	a;

	vsubtract(l, light->pos, hitter->pos);
	vnormalize(l);
	vmultiple(temp, hitter->normal,
				2. * vdot(hitter->normal, l));
	vsubtract(r, temp, l);
	vsubtract(v, hitter->pos, origin);
	vnormalize(v);
	a = fmax(vdot(r, v), 0);
	vmultiple(temp, light->color, a);
	vmultiply(specular, temp, hitter->color);	
}

void		set_color(vec color, t_light *light,
						t_hitter *hitter, vec origin)
{
	vec	diffuse;
	vec speculer;
	vec temp;

	get_diffuse(diffuse, light, hitter);
	get_specular(speculer, light, hitter, origin);
	vadd(temp, diffuse, speculer);
	vadd(color, temp, light->ambient);
	color[X] = color[X] > 1 ? 1 : color[X];
	color[Y] = color[Z] > 1 ? 1 : color[Y];
	color[Z] = color[Z] > 1 ? 1 : color[Z];
}