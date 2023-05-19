/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytrimmer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:59:31 by domy              #+#    #+#             */
/*   Updated: 2023/05/14 17:42:18 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_first_between(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (11);
		if (str[i] == '\"')
			return (12);
		i++;
	}
	return (0);
}

int	how_many(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*mytrimmer2(char *str)
{
	int		i;
	char	*ret;
	int		j;

	j = 0;
	i = 0;
	ret = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (str[i])
	{
		mytrimmer2_aux(str, ret, &i, &j);
		i++;
	}
	free(str);
	return (ret);
}

void	mytrimmer2_aux(char *str, char *ret, int *i, int *j)
{
	if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] != '\'')
		{
			ret[*j] = str[*i];
			*i += 1;
			*j += 1;
		}
	}
	else if (str[*i] == '\"')
	{
		*i += 1;
		while (str[*i] != '\"')
		{
			ret[*j] = str[*i];
			*i += 1;
			*j += 1;
		}
	}
	else
	{
		ret[*j] = str[*i];
		*j += 1;
	}
}
