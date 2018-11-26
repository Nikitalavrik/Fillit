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

int     main(int argc, char **argv)
{
    t_square	*tetriminos;
    t_square	*area;
    int			count;

	g_size = 0;
	if (argc == 2)
	{
		tetriminos = save_input(argv[1], tetriminos);
		if(g_size)
		{
			ft_putstr("OK\n");
			area = (t_square *)malloc(sizeof(t_square));
			area->row = (int *)malloc(sizeof(int) * g_size);
			if (recursion(tetriminos, area, 0))
				ft_putstr("Finish\n");
			else
				ft_putstr("errr\n");
		}
    	else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}