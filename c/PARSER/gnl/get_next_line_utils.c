/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:29:20 by seolim            #+#    #+#             */
/*   Updated: 2020/07/01 10:34:11 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *str, int *i, int len)
{
	char *new;

	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (++(*i) < len)
		new[*i] = str[*i];
	new[*i] = 0;
	return (new);
}

int		find_n(char *file)
{
	int i;

	if (!file)
		return (-1);
	i = -1;
	while (file[++i])
		if (file[i] == '\n')
			return (i);
	return (-1);
}

int		free_file(char *file)
{
	free(file);
	return (-1);
}
