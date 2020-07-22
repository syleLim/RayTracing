/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:50:31 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:59:50 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"

t_hitter	*init_hitter(void)
{
	t_hitter	*hitter;

	if (!(hitter = malloc(sizeof(t_hitter))))
		error_exit("Malloc Error Occured");
	hitter->is_hit = FALSE;
	hitter->is_shadow = FALSE;
	hitter->obj_id = -1;
	hitter->t = -1.;
	vzero(hitter->pos);
	vzero(hitter->shadow);
	vzero(hitter->color);
	return (hitter);
}
