#include "components.h"

t_components    *init_components()
{
    t_components    *comp;

    if (!(comp = malloc(sizeof(t_components))))
        exit(1);
    if (!(comp->window = init_window()))
        exit(1);
    if (!(comp->cameras[0] = init_camera()))
        exit(1);
    comp->camera_nums = 0;
    if (!(comp->screens[0] = init_screen(
                comp->cameras[0], comp->window->width, comp->window->height)))
        exit(1);
    comp->screen_nums = 0;
    if (!(comp->lights[0] = init_light()))
        exit(1);
    comp->light_nums = 0;
    vmake(comp->ambient, 0.01, 0.01, 0.01);
    return(comp);
}