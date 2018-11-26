/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:24:28 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/23 16:24:34 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*copy;
	unsigned char	unsg_c;

	i = 0;
	unsg_c = (unsigned char)c;
	dest = (unsigned char *)dst;
	copy = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = copy[i];
		if (copy[i] == unsg_c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
