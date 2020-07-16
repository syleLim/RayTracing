#ifndef LIGHTING_H
# define LIGHTING_H
# include "components.h"
# include "objects.h"
# include "shadow.h"

int		set_color(t_objs *objs, t_components *comp,
					t_hitter *hitter, vec origin);
#endif