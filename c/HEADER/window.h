#ifndef WINDOW_H
# define WINDOW_H
# include <mlx.h>
# include <stdlib.h>

typedef struct  s_window
{
    void        *mlx;
    void        *window;
    int         width;
    int         height;
    void        *img;
    int         *data;
    int         bpp;
    int         size_l;
    int         endian;
}               t_window;

t_window        *init_window();
void            set_window(t_window *window, int width, int height);

#endif