/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:38:15 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:38:30 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H
# include "window.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define HEADER_SIZE 122

void	export_bmp(char *file_name, t_window *window);

#endif
