/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:39:00 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/24 18:56:56 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_start_str(char const *s1, char const *set)
{
	size_t	i;
	int		x;
	int		is_sep;

	i = 0;
	x = 0;
	is_sep = 1;
	while (set[x] && is_sep)
	{
		if (set[x] == s1[i])
		{
			x = 0;
			i++;
		}
		else
		{
			x++;
			if (!set[x])
				is_sep = 0;
		}
	}
	if (i == ft_strlen(s1))
		return (0);
	else
		return (i);
}

int		check_end_str(char const *s1, char const *set)
{
	int		i;
	int		x;
	int		is_sep;

	i = ft_strlen(s1) - 1;
	x = 0;
	is_sep = 1;
	while (set[x] && is_sep)
	{
		if (set[x] == s1[i])
		{
			x = 0;
			i--;
		}
		else
		{
			x++;
			if (!set[x])
				is_sep = 0;
		}
	}
	if (i < 0)
		return (0);
	else
		return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	int		max_len;
	char	*str;

	i = check_start_str(s1, set);
	max_len = check_end_str(s1, set);
	y = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (max_len - i + 2))))
		return (NULL);
	while (s1[i] && i <= max_len && (i != 0 || max_len != 0))
		str[y++] = s1[i++];
	str[y] = '\0';
	return (str);
}
