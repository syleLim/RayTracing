/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:35:31 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:12:35 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "light.h"
# include "screen.h"
# include "camera.h"
# include "window.h"

typedef struct	s_components
{
	t_window	*window;
	int			light_nums;
	t_light		*lights[MAXOBJECT];
	int			camera_nums;
	t_camera	*cameras[MAXOBJECT];
	int			screen_nums;
	t_screen	*screens[MAXOBJECT];
	t_vec		ambient;
}				t_components;

t_components	*init_components();

#endif
