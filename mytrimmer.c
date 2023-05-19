/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytrimmer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:39:16 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/08 14:33:43 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	aux_trimmer(char *str, int i, char c, int new)
{
	while (str[i])
	{
		if (str[i] == c)
			new++;
		i++;
	}
	return (new);
}

char	*mytrimmer(char *str, char c)
{
	int		i;
	int		j;
	int		new;
	char	*ret;

	i = 0;
	j = 0;
	new = 0;
	new = aux_trimmer(str, i, c, new);
	ret = ft_calloc(ft_strlen(str) - new + 1, sizeof(char));
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			ret[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (ret);
}
