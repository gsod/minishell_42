/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:32:52 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/22 13:22:27 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_word(const char *s, char c)
{
	size_t	r;

	r = 0;
	while (*s)
	{
		if (*s != c)
		{
			++r;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (r);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	i = 0;
	str = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!str || !s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			str[i++] = ft_substr(s - len, 0, len);
			free(ft_substr(s - len, 0, len));
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
