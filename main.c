/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:51:29 by nlavrine          #+#    #+#             */
/*   Updated: 2018/11/11 12:51:30 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char			**ret;
	t_coordinates	*coords;
	t_coordinates	*begin;

	g_size = 0;
	if (argc == 2)
	{
		coords = NULL;
		ret = (char **)malloc(sizeof(char *) * 5);
		if ((begin = save_input(argv[1], coords, begin, ret)))
		{
			print_coords(begin);
			ft_putstr("OK\n");
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
