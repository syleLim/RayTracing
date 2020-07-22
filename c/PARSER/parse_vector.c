/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:33:21 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:06:55 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_vector(t_vec v, char *str, double div)
{
	char **strs;

	if (!(strs = ft_split(str, ',')))
		error_exit("Error\nMalloc Error Occured");
	if (ft_strslen(strs) != 3)
		error_exit("Error\n\tNot Vector in file");
	if (!check_nums(strs[X], TRUE) || !check_nums(strs[Y], TRUE)
				|| !check_nums(strs[Z], TRUE))
		error_exit("Error\n\tNot Number in Vector");
	v[X] = ft_atof(strs[X]) / div;
	v[Y] = ft_atof(strs[Y]) / div;
	v[Z] = ft_atof(strs[Z]) / div;
	ft_free_strs(strs);
}
