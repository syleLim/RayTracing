/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:30:01 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 11:42:46 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_exit(char *str)
{
	int i;

	if (!str)
		write(1, "Unkonwn Error Occured", 21);
	else
	{
		i = -1;
		while (*(str + ++i))
			write(1, str + i, 1);
	}
	write(1, "\n", 1);
	exit(1);
}
