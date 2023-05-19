/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domy <domy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:12:12 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/06 13:41:46 by domy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**smartsplit(const char *s, char c)
{
	char	**mtx;
	int		len;
	int		row;
	int		count;

	count = counter(s, c);
	if (count == -1)
		return (NULL);
	mtx = (char **) malloc(sizeof(char *) * (count + 1));
	mtx[count] = NULL;
	len = 0;
	row = 0;
	while (row < count)
	{
		len = len_funct(s, c);
		while (*s == c)
			s++;
		mtx[row] = (char *) malloc(sizeof(char) * (len + 1));
		ft_strlcpy(mtx[row], s, len + 1);
		s += len + 1;
		row++;
	}
	return (mtx);
}

int	counter(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
		{
			i = skipper(s, i, '\'');
			i = skipper(s, i, '\"');
			if (i == -1)
				return (-1);
			i++;
		}
	}
	return (count);
}

int	skipper(const char *s, int i, char c)
{
	if (i == -1)
		return (i);
	if (s[i] == c)
	{
		i++;
		while (s[i] != c && s[i])
			i++;
	}
	if (s[i] == '\0')
		return (-1);
	return (i);
}

int	len_funct(const char *str, char c)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (str[i] == c)
	{
		i++;
		l++;
	}
	while (str[i])
	{
		i = skipper(str, i, '\'');
		i = skipper(str, i, '\"');
		if (str[i] == c)
			break ;
		i++;
	}
	return (i - l);
}
