/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:10:43 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/24 15:10:44 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		put_tetriminos(t_square tetriminos, t_square *area)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		//printf("put tetriminos: ");
		//print_square(area, 1);
		if (tetriminos.row[i] + (*area).row[i] <= my_pow(2, g_size) - 1)
			(*area).row[i] += tetriminos.row[i];
		else
		{
			while (--i != -1)
				(*area).row[i] -= tetriminos.row[i];
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_put_tetriminos(t_square tetriminos, t_square *area)
{
	if (check_overlay(tetriminos, *area))
		return (put_tetriminos(tetriminos, area));
	else
	{
		printf("area: ");
		print_square(area, 1);
		printf("before: ");
		print_square(&tetriminos, 1);
		if (check_right_shift(tetriminos))
		{
			printf("right shift\n");
			tetriminos = shift_right_tetriminos(tetriminos);
		}
		else if (check_up_shift(tetriminos))
		{
			printf("up shift\n");
			tetriminos = shift_up_tetriminos(tetriminos);
		}
		else if (check_left_shift(tetriminos))
		{
			printf("left shift\n");
			tetriminos = shift_left_tetriminos(tetriminos);
		}
		else if (check_down_shift(tetriminos))
		{
			printf("down shift\n");
			tetriminos = shift_down_tetriminos(tetriminos);
		}
		else
			return (0); 
		printf("after: ");
		print_square(&tetriminos, 1);
	}
	return (check_put_tetriminos(tetriminos, area));
	return (0);
}

int		recursion(t_square *tetriminos, t_square *area, int index)
{
	printf("index = %i\n", index);
	if (index == 4)
		return (1);
	if (index == -1)
		return (0);
	if (check_put_tetriminos(tetriminos[index], area))
		recursion(tetriminos, area, ++index);
	else
		recursion(tetriminos, area, --index);
	return (0);
}