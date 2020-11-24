/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:35:14 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/24 15:15:24 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*mem;
	size_t	i;

	if (!(mem = malloc(element_size * element_count)))
		return (NULL);
	i = 0;
	while (i < element_count)
		mem[i++] = 0;
	return ((void *)mem);
}
