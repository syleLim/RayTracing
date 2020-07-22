/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:47:17 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:13:45 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H
# include "db.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_square
{
	int			id;
	double		size;
	t_vec		pos;
	t_vec		normal;
	t_vec		color;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_vec		d;
}				t_square;

t_square		*init_square();
void			set_abcd(t_square *square, double size, t_vec normal);
void			set_square_normal(t_square *square, t_vec normal);
void			set_square_size(t_square *square, double size);
void			set_square_pos(t_square *square, t_vec pos);
void			set_square_color(t_square *square, t_vec color);
void			shadow_collision_square(t_square *square,
							t_ray *ray, t_hitter *hitter);
void			collision_square(t_square *square,
						t_ray *ray, t_hitter *hitter);

#endif
