#ifndef TRACER_H
# define TRACER_H
# include "objects.h"
# include "light.h"

void	tracing(t_objs *objs, t_light *light,
					t_hitter *hitter, t_ray *ray,
					t_camera *camera, t_screen *screen);

#endif