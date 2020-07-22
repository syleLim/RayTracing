/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:25:44 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 10:26:31 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static double	cal_decimal(char *str, double sign)
{
	double	decimal;
	double	digit;

	decimal = 0.;
	digit = 0.1;
	while (*str && ft_is_num(*str))
	{
		decimal += digit * (double)(*str - '0') * sign;
		digit *= 0.1;
		str++;
	}
	return (decimal);
}

double			ft_atof(char *str)
{
	double	sign;
	double	num;
	char	**int_decimal;

	int_decimal = ft_split(str, '.');
	sign = *str == '-' ? -1 : 1;
	if (ft_strslen(int_decimal) == 1)
		num = (double)ft_atoi(int_decimal[0]);
	else
		num = (double)ft_atoi(int_decimal[0])
			+ cal_decimal(int_decimal[1], sign);
	free(int_decimal);
	return (num);
}
