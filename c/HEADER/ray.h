/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:43:44 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:51:34 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <stdlib.h>
# include "db.h"
# include "vector.h"
# include "screen.h"

typedef	struct	s_ray
{
	t_vec		origin;
	t_vec		dir;
}				t_ray;

t_ray			*init_ray();
void			set_ray_origin(t_ray *ray, t_vec origin);
void			set_ray_dir(t_ray *ray, t_vec dir);
void			cal_ray_dir(t_ray *ray,
				t_screen *screen, double u, double v);

#endif
