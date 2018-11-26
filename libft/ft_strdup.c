/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:29:00 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/25 16:29:19 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dest;

	i = -1;
	len = ft_strlen(s1);
	if (!(dest = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (++i < len)
		dest[i] = s1[i];
	dest[len] = '\0';
	return (dest);
}
