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

t_screen	*init_screen(t_camera *camera, int w, int h);
void		set_screen_wh(t_screen *screen,
						int width, int height);
void		set_screen_vector(t_screen *screen, t_camera *camera);

#endif