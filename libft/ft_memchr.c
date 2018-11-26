/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:59:17 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/23 16:59:18 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	t;
	unsigned char	*copy;

	i = 0;
	t = (unsigned char)c;
	copy = (unsigned char *)s;
	while (i < n)
	{
		if (copy[i] == t)
			return (copy + i);
		i++;
	}
	return (NULL);
}
