#include "hitter.h"

t_hitter	*init_hitter()
{
	t_hitter	*hitter;

	if (!(hitter = malloc(sizeof(t_hitter))))
		return (NULL);
	hitter->is_hit = FALSE;
	hitter->is_shadow = FALSE;
	hitter->obj_id = -1;
	hitter->t = -1.;
	vzero(hitter->pos);
	vzero(hitter->shadow);
	vzero(hitter->color);
	return (hitter);
}

void		clear_hitter(t_hitter *hitter)
{
	hitter->is_hit = FALSE;
	hitter->is_shadow = FALSE;
	hitter->obj_id = -1;
	hitter->t = -1.;
	vzero(hitter->pos);
	vzero(hitter->shadow);
	vzero(hitter->color);
}

void		set_hitter_pos(t_hitter *hitter, vec pos)
{
	vcopy(hitter->pos, pos);
}

void		set_hitter_shadow_ray(t_hitter *hitter, vec shadow)
{
	vcopy(hitter->shadow, shadow);
}

void		set_hitter_color(t_hitter *hitter, vec color, int id)
{
	hitter->obj_id = id;
	vcopy(hitter->color, color);
}

bool		check_hitter(t_hitter *hitter, vec pos, vec origin, vec normal)
{
	if (hitter->t > vdiff(pos, origin)
			|| !hitter->is_hit)
	{
		vcopy(hitter->pos, pos);
		vcopy(hitter->normal, normal);
		hitter->t = vdiff(pos, origin);
		hitter->is_hit = TRUE;
		return (TRUE);
	}
	return (FALSE);
}