/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:50:03 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/11 12:50:04 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct  s_square
{
    int         *row;
	int			size;
    char        fill_c;
}               t_square;

t_square	*save_input(char *filename, t_square *tetriminos);

int			recursion(t_square *tetriminos, t_square *area, int index);

void		print_square(t_square *tetriminos, int count);

void		fill_row(int *row, int c, int size);

int			check_overlay(t_square tetriminos, t_square area);

int     	check_right_shift(t_square tetriminos);

int     	check_left_shift(t_square tetriminos);

int			check_up_shift(t_square tetriminos);

int			check_down_shift(t_square tetriminos);

t_square	shift_right_tetriminos(t_square tetriminos);

t_square	shift_left_tetriminos(t_square tetriminos);

t_square	shift_up_tetriminos(t_square tetriminos);

t_square	shift_down_tetriminos(t_square tetriminos);

int			my_pow(int num, int pow);

int			g_size;

#endif