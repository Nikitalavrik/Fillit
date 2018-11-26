/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:28:07 by nlavrine          #+#    #+#             */
/*   Updated: 2018/10/30 18:28:08 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	ptr_size;
	char	*ret;

	ptr_size = ft_strlen(ptr);
	if (ptr_size < size)
	{
		ret = ft_memcpy(ft_memalloc(size), ptr, size);
		ft_memdel(&ptr);
		return (ret);
	}
	return (ptr);
}
