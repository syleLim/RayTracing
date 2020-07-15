#ifndef GAME_H
# define GAME_H
# include "components.h"
# include "objects.h"

typedef struct		s_game
{
	t_components	*components;
	t_objs			*objs;
}					t_game;

t_game				*init_game();

#endif