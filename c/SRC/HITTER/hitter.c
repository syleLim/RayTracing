#include "hitter.h"

t_hitter	*init_hitter()
{
	t_hitter	*hitter;

	if (!(hitter = malloc(sizeof(t_hitter))))
		return (NULL);
	vzero(hitter->pos);
	vzero(hitter->shadow);
	return (hitter);
}

void		set_hitter_pos(t_hitter *hitter, vec pos)
{
	vcopy(hitter->pos, pos);
}

void		set_hitter_shadow_ray(t_hitter *hitter, vec shadow)
{
	vcopy(hitter->shadow, shadow);
}