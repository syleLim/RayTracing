/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:44:06 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:51:43 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include <stdlib.h>
# include "db.h"
# include "vector.h"
# include "camera.h"

typedef struct	s_screen
{
	int			width;
	int			height;
	t_vec		origin;
	t_vec		vertical;
	t_vec		horizontal;
}				t_screen;

t_screen		*init_screen(t_camera *camera, int w, int h);
void			set_screen_wh(t_screen *screen,
						int width, int height);
void			set_screen_vector(t_screen *screen, t_camera *camera);

#endif
