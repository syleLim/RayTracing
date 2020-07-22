/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:34:51 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:59:08 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void		set_light_color(t_light *light, t_vec color)
{
	vcopy(light->color, color);
}

void		set_light_pos(t_light *light, t_vec pos)
{
	vcopy(light->pos, pos);
}
