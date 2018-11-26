/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:57:59 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/24 15:57:59 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int     check_right_shift(t_square tetriminos)
{
	int     i;

    i = 0;
    while (i++ < g_size)
		if (tetriminos.row[i] & 1)
			return (0);
	return (1);
}

int		check_overlay(t_square tetriminos, t_square area)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		if (tetriminos.row[i] & area.row[i])
			return (0);
		i++;
	}
	return (1);
}

int     check_left_shift(t_square tetriminos)
{
	int     i;

    i = 0;
    while (i++ < g_size)
		if ((tetriminos.row[i] >> (g_size - 1)) & 1)
			return (0);
	return (1);
}

int		check_up_shift(t_square tetriminos)
{
	return (!tetriminos.row[0]);
}

int		check_down_shift(t_square tetriminos)
{
	return (!tetriminos.row[g_size - 1]);
}