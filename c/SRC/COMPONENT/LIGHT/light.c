#include "light.h"

t_light		*init_light()
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	vzero(light->pos);
	vmake(light->color, 1, 1, 1);
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