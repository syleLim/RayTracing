#include "light.h"

t_light		*init_light(vec pos, double intensity,
							double ambient)
{
	t_light	*light;

	if (!(light = malloc(sizeof(light))))
		return (NULL);
	vcopy(light->pos, pos);
	light->intensity = intensity;
	light->ambient = ambient;
	return (light);	
}