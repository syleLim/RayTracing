#include "hitter.h"

t_hitter	*init_hitter()
{
	t_hitter	*hitter;

	if (!(hitter = malloc(sizeof(t_hitter))))
		return (NULL);
	vzero(hitter->pos);
	vzero(hitter->shadow_ray);
	return (hitter);
}