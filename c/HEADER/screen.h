#ifndef SCREEN_H
# define SCREEN_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"
# include "camera.h"

typedef struct	s_screen
{
	int			width;
	int			height;
	vec			origin;
	vec			vertical;
	vec			horizontal;
}				t_screen;

t_screen	*init_screen(double width, double height);

#endif