#ifndef SHADOW_H
# define SHADOW_H
# include "objects.h"
# include "light.h"

void    check_shadow(t_objs *objs, t_hitter *hitter,
                                t_light *light);
#endif