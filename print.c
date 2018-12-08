/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:16:22 by nlavrine          #+#    #+#             */
/*   Updated: 2018/12/03 18:16:22 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_square(t_square *tetriminos, int count)
{
	int		i;
	int		len;

	i = 0;
	while(i < count)
	{
		printf("char = %c size = %i\n", tetriminos[i].fill_c, tetriminos[i].size);
		len = 0;
		while (len < tetriminos[i].size)
		{
			printf("%i  ", tetriminos[i].row[len]);
			len++;
		}
		printf("\n");
		i++;
	}
}

// void	print_coords(t_coordinates *coords)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < g_size)
// 	{
// 		j = 0;
// 		printf("Figure #%i\n", i + 1);
// 		while (j < 4)
// 		{
// 			printf("x = %i y = %i\n", coords[i].row_x[j], coords[i].row_y[j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int		check_coord(int x, int y, t_coordinates coord)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (x == coord.row_x[i] && y == coord.row_y[i])
// 				return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	print_figures_by_coords(t_coordinates *coords)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	while (i < g_size)
// 	{
// 		j = 0;
// 		while (j < 4)
// 		{
// 			k = 0;
// 			while (k < 4)
// 			{
// 				if (check_coord(k + 1, j + 1, coords[i]))
// 					ft_putchar(coords[i].fill_c);
// 				else
// 					ft_putchar('.');
// 				k++;
// 			}
// 			ft_putchar('\n');
// 			j++;
// 		}
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

void	print_ret(char **ret, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		ft_putstr(ret[i]);
		ft_putchar('\n');
	}
		
}

void	print_coords(t_coordinates *coords)
{
	int		i;
	int		j;

	i = 1;
	while(coords)
	{
		printf("Figure #%d\n", i);
		j = 0;
		while (j < 4)
		{
			printf("y = %d x = %d\n", coords->row_y[j], coords->row_x[j]);
			j++;
		}
		printf("\n");
		i++;
		coords = coords->next;
	}
}