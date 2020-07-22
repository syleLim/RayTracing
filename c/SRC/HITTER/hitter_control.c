/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:50:27 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:11:19 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"

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

void		set_hitter_pos(t_hitter *hitter, t_vec pos)
{
	vcopy(hitter->pos, pos);
}

void		set_hitter_shadow_ray(t_hitter *hitter, t_vec shadow)
{
	vcopy(hitter->shadow, shadow);
}

void		set_hitter_color(t_hitter *hitter, t_vec color, int id)
{
	hitter->obj_id = id;
	vcopy(hitter->color, color);
}

t_bool		check_hitter(t_hitter *hitter, t_vec pos,
					t_vec origin, t_vec normal)
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
