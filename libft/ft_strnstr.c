/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:36:02 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/26 14:36:07 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	dst_len;
	size_t	find_len;

	i = -1;
	dst_len = ft_strlen(haystack);
	find_len = ft_strlen(needle);
	while (++i <= (dst_len - find_len) && dst_len >= find_len\
	&& (i + find_len) <= len)
		if (!ft_memcmp(haystack + i, needle, find_len))
			return ((char *)(haystack + i));
	return (NULL);
}
