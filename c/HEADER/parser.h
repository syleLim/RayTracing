/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:41:02 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:53:00 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include <unistd.h>
# include "game.h"
# include "get_next_line.h"

double	ft_atof(char *str);
int		ft_atoi(const char *str);
int		ft_is_num(char c);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		ft_strslen(char **strs);
t_bool	ft_free_strs(char **strs);
t_bool	check_nums(char *str, int flag);
void	parse_vector(t_vec v, char *str, double div);
int		parsing_triangle(t_objs *objs, char **info);
int		parsing_sphere(t_objs *objs, char **info);
int		parsing_square(t_objs *objs, char **info);
int		parsing_cylinder(t_objs *objs, char **info);
int		parsing_plane(t_objs *objs, char **info);
int		parsing_light(t_components *comp, char **info);
int		parsing_camera(t_components *comp, char **info);
int		parsing_ambient(t_vec ambient, char **info);
int		parsing_window(t_components *components, char **info);
void	parsing(int fd, t_objs *objs, t_components *comp);

#endif
