/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:42:31 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:43:26 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

typedef double	t_quaternion[4];

void			qmake(t_quaternion q, double xyz[3], double w);
void			qorthogonal(t_quaternion q, double u[3]);
void			qrotate(double v[3], t_quaternion q);

#endif
