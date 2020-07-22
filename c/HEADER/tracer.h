/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:47:29 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:47:33 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H
# include "parser.h"
# include "lighting.h"
# include "shadow.h"

void	tracing(t_objs *objs, t_components *comp,
				int camera_id);

#endif
