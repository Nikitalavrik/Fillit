/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:44:11 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/24 15:44:11 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	shift_right_tetriminos(t_square tetriminos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tetriminos.row[i] = tetriminos.row[i] >> 1;
		i++;
	}
	return (tetriminos);
}


t_square	shift_left_tetriminos(t_square tetriminos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tetriminos.row[i] = tetriminos.row[i] << 1;
		i++;
	}
	return (tetriminos);
}

t_square	shift_up_tetriminos(t_square tetriminos)
{
	int		i;

	i = 0;
	//printf("shifting : \n");
	while (i < 3)
	{
		//printf("%i swap %i\n", tetriminos.row[i], tetriminos.row[i + 1]);
		tetriminos.row[i] = tetriminos.row[i + 1];
		i++;
	}

	tetriminos.row[i] = 0;
	return (tetriminos);
}

t_square	shift_down_tetriminos(t_square tetriminos)
{
	int		i;

	i = 4;
	//tetriminos.row[0] = 0;
	while (--i != -1)
		tetriminos.row[i] = tetriminos.row[i - 1];
	return (tetriminos);
}

int			my_pow(int num, int pow)
{
	int		sum;

	sum = num;
	while (--pow)
		sum *= num;
	return (sum);
}