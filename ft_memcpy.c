/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:16:18 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/24 16:20:03 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char *dest;
	char *src;

	dest = (char *)destination;
	src = (char *)source;
	if (!src && !dest)
		return (NULL);
	while (size--)
		*dest++ = *src++;
	return (destination);
}
