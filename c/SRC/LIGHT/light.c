#include "light.h"

t_light	*init_light()
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	vzero(light->pos);
	vmake(light->color, 1, 1, 1);
	light->intensity = 1.;
	light->ambient = 0.;
	return (light);	
}

void	set_light_color(t_light *light, vec color)
{
	vmake(light->color, 
		color[X] / 256., color[Y] / 256., color[Z] / 256.);
}

void	set_light_pos(t_light *light, vec pos)
{
	vcopy(light->pos, pos);
}

void	set_intensity(t_light *light, double intensity)
{
	light->intensity = intensity;
}

void	set_ambient(t_light *light, double ambient)
{
	light->ambient = ambient;
}