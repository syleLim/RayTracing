#ifndef EXPORT_H
# define EXPORT_H
# include "window.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define HEADER_SIZE 122

void	export_bmp(char *file_name, t_window *window);
#endif