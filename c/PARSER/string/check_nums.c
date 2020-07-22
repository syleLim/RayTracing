/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:32:12 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:52:22 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	check_nums(char *str, int flag)
{
	int	i;
	int	point;

	if (!str)
		return (FALSE);
	i = *str == '-' && flag ? 0 : -1;
	point = 0;
	while (*(str + (++i)))
	{
		if (!ft_is_num(*(str + i)))
		{
			if (*(str + i) == '.' && point == 0 && flag)
				point++;
			else
				return (FALSE);
		}
	}
	return (TRUE);
}
