/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:50:23 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:18:15 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# include "db.h"
# include "quaternion.h"

typedef double	t_vec[3];

void	vcopy(t_vec dest, t_vec src);
void	vzero(t_vec v);
void	vmake(t_vec dest, double x, double y, double z);
void	vcross(t_vec dest, t_vec v1, t_vec v2);
double	vlen(t_vec v);
void	vmultiple(t_vec dest, t_vec src, double value);
void	vmultiply(t_vec dest, t_vec v1, t_vec v2);
void	vnormalize(t_vec v);
void	vneg(t_vec dest, t_vec src);
double	vdot(t_vec v1, t_vec v2);
t_bool	vcompare(t_vec v1, t_vec v2);
t_bool	vcompare_neg(t_vec v1, t_vec v2);
void	vrotate(t_vec v, t_vec u, t_vec ori);
double	vdiff(t_vec v1, t_vec v2);
void	vsubtract(t_vec dest, t_vec v1, t_vec v2);
void	vpoint(t_vec dest, t_vec origin, t_vec dir, double t);
void	vadd(t_vec dest, t_vec v1, t_vec v2);

#endif
