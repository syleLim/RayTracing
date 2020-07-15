#include "components.h"

t_components    *init_components()
{
    t_components    *comp;

    if (!(comp = malloc(sizeof(t_components))))
        exit(1);
    if (!(comp->window = init_window()))
        exit(1);
    if (!(comp->camera = init_camera()))
        exit(1);
    if (!(comp->screen = init_screen()))
        exit(1);
    if (!(comp->light = init_light()))
        exit(1);
    return(comp);
}