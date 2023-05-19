/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:56:11 by mepifano          #+#    #+#             */
/*   Updated: 2023/05/14 15:53:11 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *str, char const *set)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				start++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		j;
	int		start;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0' && end > 0)
	{
		if (s1[end] == set[j])
		{
			end--;
			j = 0;
		}		
		else
			j++;
	}
	str = ft_substr(s1, start, end - start + 1);
	free((char *)s1);
	return (str);
}
