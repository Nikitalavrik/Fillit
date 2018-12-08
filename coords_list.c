/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:27:25 by nlavrine          #+#    #+#             */
/*   Updated: 2018/12/08 13:27:32 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coordinates	*create_coords(void)
{
	t_coordinates *coords;

	coords = (t_coordinates *)malloc(sizeof(t_coordinates));
	coords->row_x = (int *)malloc(sizeof(int) * 4);
	coords->row_y = (int *)malloc(sizeof(int) * 4);
	coords->next = NULL;
	return (coords);
}

t_coordinates	*add_coords(t_coordinates *coords, int number, int x, int y)
{
	if (!coords)
		coords = create_coords();
	coords->row_x[number] = x + 1;
	coords->row_y[number] = y + 1;
	return (coords);
}

void			add_to_end(t_coordinates **coords, t_coordinates *tmp_coord)
{
	if (!g_size)
		*coords = tmp_coord;
	else
	{
		(*coords)->next = tmp_coord;
		(*coords) = tmp_coord;
	}
}
