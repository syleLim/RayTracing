/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:40:21 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:50:46 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H
# include "components.h"
# include "objects.h"
# include "shadow.h"

int		set_color(t_objs *objs, t_components *comp,
					t_hitter *hitter, t_vec origin);
#endif
