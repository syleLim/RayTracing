/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:38:35 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:38:47 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "components.h"
# include "objects.h"

typedef struct		s_game
{
	int				camera_id;
	t_components	*components;
	t_objs			*objs;
}					t_game;

t_game				*init_game();

#endif
