/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:39:29 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:13:22 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_H
# define HITTER_H
# include <stdlib.h>
# include "db.h"
# include "vector.h"
# include "error.h"

typedef struct	s_hitter
{
	t_bool		is_hit;
	t_bool		is_shadow;
	int			obj_id;
	t_vec		pos;
	t_vec		normal;
	t_vec		color;
	t_vec		shadow;
	double		t;
}				t_hitter;

t_hitter		*init_hitter();
void			set_hitter_pos(t_hitter *hitter, t_vec pos);
void			set_hitter_shadow_ray(t_hitter *hitter, t_vec shadow);
void			set_hitter_color(t_hitter *hitter, t_vec color, int id);
t_bool			check_hitter(t_hitter *hitter, t_vec pos,
							t_vec origin, t_vec normal);
void			clear_hitter(t_hitter *hitter);

#endif
