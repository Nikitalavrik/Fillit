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

typedef struct	s_coordinates
{
	int				*row_x;
	int				*row_y;
	struct s_coordinates	*next;
	char			fill_c;
}				t_coordinates;

t_coordinates	*add_coords(t_coordinates *coords, int number, int x, int y);

t_coordinates	*create_coords(void);

void			add_to_end(t_coordinates **coords, t_coordinates *tmp_coord);

t_coordinates	*save_input(char *filename, t_coordinates *coords,\
t_coordinates *begin, char **ret);

int				recursion(t_square *tetriminos, t_square *area, int index);

void			print_square(t_square *tetriminos, int count);

void			fill_row(int *row, int c, int size);

int				check_overlay(t_square tetriminos, t_square area);

int     		check_right_shift(t_square tetriminos);

int     		check_left_shift(t_square tetriminos);

int				check_up_shift(t_square tetriminos);

int				check_down_shift(t_square tetriminos);

t_square		shift_right_tetriminos(t_square tetriminos);

t_square		shift_left_tetriminos(t_square tetriminos);

t_square		shift_up_tetriminos(t_square tetriminos);

t_square		shift_down_tetriminos(t_square tetriminos);

t_square 		shift_tetriminos(t_square tetriminos);

void			print_coords(t_coordinates *coords);

void			print_square(t_square *tetriminos, int count);

void			print_figures_by_coords(t_coordinates *coords);

void			print_ret(char **ret, int size);

int				my_pow(int num, int pow);

int				free_space(void **ret);

int				g_size;

#endif