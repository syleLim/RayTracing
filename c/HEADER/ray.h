#ifndef RAY_H
# define RAY_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"
# include "screen.h"

typedef	struct	s_ray
{
	vec			origin;
	vec			dir;
}				t_ray;

t_ray	*init_ray();
void	set_ray_origin(t_ray *ray, vec origin);
void	set_ray_dir(t_ray *ray, vec dir);
void	cal_ray_dir(t_ray *ray,
				t_screen *screen, double u, double v);

#endif