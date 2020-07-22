/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:44:18 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:46:57 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H
# include "objects.h"
# include "light.h"

void	check_shadow(t_objs *objs, t_hitter *hitter,
					t_light *light);

#endif
