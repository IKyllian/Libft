/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:35:14 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/25 09:23:24 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*mem;

	if (!(mem = malloc(element_size * element_count)))
		return (NULL);
	ft_memset(mem, 0, element_count * element_size);
	return ((void *)mem);
}
