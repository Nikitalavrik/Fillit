/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:49:40 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/11 12:49:41 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		bit_add(int j)
{
	if (j == 0)
		return (8);
	if (j == 1)
		return (4);
	if (j == 2)
		return (2);
	if (j == 3)
		return (1);
	return (0);
}

void	fill_row(int *row, int c, int size)
{
	int	i;

	i = 0;
	while (i < size)
		row[i++] = c;
}

int		check_row(int *row)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < 4)
		sum += row[i++];
	i = 0;
	while (i < 3)
	{
		sum -= row[i];
		if (row[i] && ((sum  && !row[i + 1]) || (!(row[i] & row[i + 1]) && row[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int		check_input(char **ret, int index, t_square *tetriminos, char ch)
{
	int i;
	int	j;
	int len;
	int	count;

	if (((index - (index / 4 - 1))  % 4) != 0)
		return (0);
	i = index - 5;
	count = 0;
	tetriminos->row = (int *)malloc(sizeof(int) * 4);                                                                     
	fill_row(tetriminos->row, 0, 4);
	//printf("begin i = %d\nindex = %i\n", i, index);
	while (++i < index)
	{
		j = -1;
		len = ft_strlen(ret[i]);
		//printf("i = %i\n", i - (5 * (index/4 - 1)));
		while (++j < len)
		{
			if (ret[i][j] != '.' && ret[i][j] != '#')
				return (0);
			if (ret[i][j] == '#')
			{
				ret[i][j] = ch;
				tetriminos->row[i - (5 * (index/4 - 1))] += bit_add(j);
				count++;
			}
		}
	}
	tetriminos->fill_c = ch;
	tetriminos->size = 4;
	//printf("end i = %i\n", i);
	return (count == 4 && check_row(tetriminos->row));
}

void	print_square(t_square *tetriminos, int count)
{
	int		i;
	int		len;

	i = 0;
	while(i < count)
	{
		printf("char = %c size = %i\n", tetriminos[i].fill_c, tetriminos[i].size);
		len = 0;
		while (len < 4)
		{
			printf("%i  ", tetriminos[i].row[len]);
			len++;
		}
		printf("\n");
		i++;
	}
}

t_square	*save_input(char *filename, t_square *tetriminos)
{
	int		i;
	int		fd;
	int		len;
	char	**ret;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	i = -1;
	ret = (char **)malloc(sizeof(char *) * 100);
	tetriminos = (t_square *)malloc(sizeof(t_square)*25);
	while (get_next_line(fd, &ret[++i]))
	{
		len = ft_strlen(ret[i]);
		if (len == 0)
		{
			//printf("i = %i\n", i/4 -1);
			if (!(check_input(ret, i, &tetriminos[i/4 -1], 'A' + i /4 - 1)))
				return (NULL);
		}
		else if (len < 4 || len > 4)
			return (NULL);
	}
	print_square(tetriminos, i/4 -1);
	ret[i] = NULL;
	while (*ret)
		printf("%s\n", *ret++);
	g_size = i / 4 - 1;
	return (tetriminos);
}