/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:00:10 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/25 18:00:11 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	src_len;

	i = -1;
	len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (src[++i] && ((i + len + 1) < dstsize))
		dst[len + i] = src[i];
	dst[len + i] = '\0';
	if (dstsize < len)
		return (dstsize + src_len);
	return (len + src_len);
}
