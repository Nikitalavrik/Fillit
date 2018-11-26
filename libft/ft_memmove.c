/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:41:54 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/23 16:41:57 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*copy;

	i = -1;
	dest = (unsigned char *)dst;
	copy = (unsigned char *)src;
	if (dst > src)
		dest = ft_memcpy(dst, src, n);
	else
		while (++i < n)
			dest[i] = copy[i];
	return (dest);
}
