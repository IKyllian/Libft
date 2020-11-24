/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:01:04 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/24 11:36:01 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sep(char str, char sep)
{
	if (!str)
		return (0);
	if (str == sep)
		return (-1);
	return (0);
}

int		*get_strings_len(char const *str, char sep, int **starts, int size)
{
	int i;
	int x;
	int *strings_len;

	i = 0;
	if (!(strings_len = (int *)malloc(sizeof(*strings_len) * size)))
		return (NULL);
	if (!(*starts = (int *)malloc(sizeof(**starts) * size)))
		return (NULL);
	x = is_sep(str[0], sep);
	while (str[i])
	{
		strings_len[x] = 0;
		if (str[i] && (!is_sep(str[i], sep)))
			(*starts)[x] = i;
		while (str[i] && (!is_sep(str[i], sep)))
		{
			strings_len[x] += 1;
			i++;
		}
		x++;
		while (str[i] && is_sep(str[i], sep))
			i++;
	}
	return (strings_len);
}

void	ft_fill_tab(char const *str, char **output, int *starts, int *s_len)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (i == *starts)
		{
			if (!(output[x] = malloc(sizeof(**output) * (*s_len + 1))))
				return ;
			while (i++ - *starts < *s_len)
				output[x][i - *starts - 1] = str[i - 1];
			output[x][i - *starts - 1] = '\0';
			starts++;
			s_len++;
			x++;
		}
		else
			i++;
	}
	output[x] = 0;
}

int		ft_get_tab_len(char const *str, char sep)
{
	int i;
	int x;

	i = 0;
	x = is_sep(str[0], sep);
	while (str[i])
	{
		while (str[i] && (!is_sep(str[i], sep)))
			i++;
		x++;
		while (str[i] && is_sep(str[i], sep))
			i++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		*starts;
	int		*strings_len;
	char	**output;

	len = ft_get_tab_len(s, c);
	strings_len = get_strings_len(s, c, &starts, len);
	if (!(output = malloc(sizeof(*output) * (len + 1))))
		return (NULL);
	if (len)
		ft_fill_tab(s, output, starts, strings_len);
	else
		output[0] = 0;
	return (output);
}
