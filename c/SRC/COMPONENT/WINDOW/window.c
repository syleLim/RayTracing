#include "window.h"

t_window    *init_window()
{
    t_window    *window;

    if (!(window = malloc(sizeof(t_window))))
        return (NULL);
    window->width = 640;
    window->height = 480;
    window->mlx = mlx_init();
    window->window = mlx_new_window(window->mlx, 640, 480, "tester");
	window->img = mlx_new_image(window->mlx, 640, 480);
    window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
                                            &window->size_l, &window->endian);
    return (window);
}

void        set_window(t_window *window, int width, int height)
{
    window->width = width;
    window->height = height;
    mlx_destroy_window(window->mlx, window->window);
    mlx_destroy_image(window->mlx, window->img);
    window->mlx = mlx_init();
    window->window = mlx_new_window(window->mlx, width, height, "tester");
	window->img = mlx_new_image(window->mlx, width, height);
    window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
                                            &window->size_l, &window->endian);   
}
