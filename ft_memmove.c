/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:17:20 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/24 11:04:54 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	char *dest;
	char *src;

	dest = (char *)destination;
	src = (char *)source;
	while (n--)
	{
		if (*src++ == *dest++)
			return (destination);
	}
	return (destination);
}
