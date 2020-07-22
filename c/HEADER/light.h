/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:40:08 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:50:50 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include <stdlib.h>
# include "db.h"
# include "vector.h"
# include "hitter.h"

typedef struct	s_light
{
	t_vec		pos;
	t_vec		color;
}				t_light;

t_light			*init_light();
void			set_light_pos(t_light *light, t_vec pos);
void			set_light_color(t_light *light, t_vec color);

#endif
