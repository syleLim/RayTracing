#ifndef COMPONENTS_H
# define COMPONENTS_H
#include "light.h"
#include "screen.h"
#include "camera.h"
#include "window.h"

typedef struct  s_components
{
    t_window    *window;
    t_light     *light;
    t_camera    *camera;
    t_screen    *screen;
}               t_components;

t_components    *init_components();

#endif