#include "hitter.h"

t_hitter	*init_hitter()
{
	t_hitter	*hitter;

	if (!(hitter = malloc(sizeof(t_hitter))))
		return (NULL);
	hitter->is_hit = FALSE;
	vzero(hitter->pos);
	vzero(hitter->shadow);
	vzero(hitter->color);
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

void		set_hitter_color(t_hitter *hitter, vec color)
{
	vcopy(hitter->color, color);
}

bool		check_hitter(t_hitter *hitter, vec pos, vec origin, vec normal)
{
	if (vdiff(hitter->pos, origin) < vdiff(pos, origin)
			&& hitter->is_hit)
		return (FALSE);
	vcopy(hitter->pos, pos);
	vcopy(hitter->normal, normal);
	hitter->is_hit = TRUE;
	return (TRUE);
}