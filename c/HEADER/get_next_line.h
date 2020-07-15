/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:28:10 by seolim            #+#    #+#             */
/*   Updated: 2020/07/15 16:12:45 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define MAX_FD			500
# define BUFFER_SIZE    15

int		ft_strlen(char *str);
int		find_n(char *file);
char	*strjoin(char *s1, char *s2, int s2_len);
int		free_file(char *file);
char	*ft_strdup(char *str, int *i, int len);
int		get_next_line(int fd, char **line);

#endif
