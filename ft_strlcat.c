/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:32:01 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/23 13:34:39 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int dlength;

	i = 0;
	dlength = 0;
	while (dest[dlength] == '\0')
		dlength++;
	while (i < size - dlength - 1 && src[i] != '\0')
	{
		dest[dlength + i] = src[i];
		i++;
	}
	if (dlength != size)
		dest[dlength + i] = '\0';
	return (dlength + ft_strlen(src));
}