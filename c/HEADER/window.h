/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:52:57 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:53:46 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <mlx.h>
# include <stdlib.h>
# include "error.h"

typedef struct	s_window
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_window;

t_window		*init_window();
void			set_window(t_window *window, int width, int height);

#endif
