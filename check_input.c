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

int				check_conn(char **ret, int i, int j, int *count_sharp)
{
	int count;

	count = 0;
	(*count_sharp)++;
	if (i > 0 && ret[i - 1][j] == '#')
		count++;
	if (i < 3 && ret[i + 1][j] == '#')
		count++;
	if (j > 0 && ret[i][j - 1] == '#')
		count++;
	if (j < 3 && ret[i][j + 1] == '#')
		count++;
	return (count);
}

void			set_parameters(int *i, int *conn, int *count,\
											t_coordinates **tmp_coord)
{
	*i = -1;
	*conn = 0;
	*count = 0;
	*tmp_coord = NULL;
}

int				check_input(char **ret, char ch, t_coordinates **coords)
{
	int				i;
	int				j;
	int				count;
	int				conn;
	t_coordinates	*tmp_coord;

	set_parameters(&i, &conn, &count, &tmp_coord);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((ret[i][j] != '.' && ret[i][j] != '#'))
				return (0);
			if (ret[i][j] == '#')
			{
				if (count == 4)
					return (0);
				tmp_coord = add_coords(tmp_coord, count, j, i);
				conn += check_conn(ret, i, j, &count);
			}
		}
	}
	add_to_end(coords, tmp_coord);
	return (count == 4 && (conn == 6 || conn == 8));
}

int				check_file(char *filename, int *fd, int *i, int *last)
{
	*i = -1;
	*last = 1;
	if ((*fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	return (*fd);
}

t_coordinates	*save_input(char *filename, t_coordinates *coords,\
											t_coordinates *begin, char **ret)
{
	int				i;
	int				fd;
	int				len;
	int				last;

	fd = check_file(filename, &fd, &i, &last);
	while (get_next_line(fd, &ret[++i]) || last--)
	{
		len = ft_strlen(ret[i]);
		if (i == 4 && len == 0)
		{
			if (!(check_input(ret, 'A' + g_size, &coords)))
				return (NULL);
			if (!g_size)
				begin = coords;
			g_size++;
			i = -1;
		}
		else if (len < 4 || len > 4)
			return (0);
	}
	ret[5] = NULL;
	free_space((void **)ret);
	return (begin);
}
