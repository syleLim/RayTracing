#ifndef COMPONENTS_H
# define COMPONENTS_H
#include "light.h"
#include "screen.h"
#include "camera.h"
#include "window.h"

typedef struct  s_components
{
    t_window    *window;
    int         light_nums;
    t_light     *lights[MAXOBJECT];
    int         camera_nums;
    t_camera    *cameras[MAXOBJECT];
    int         screen_nums;
    t_screen    *screens[MAXOBJECT];
    vec         ambient;
}               t_components;

t_components    *init_components();

#endif