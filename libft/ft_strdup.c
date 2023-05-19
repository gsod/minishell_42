/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:45 by rpoggi            #+#    #+#             */
/*   Updated: 2022/02/08 17:19:19 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		c;
	char	*copy;

	c = 0;
	while (s[c])
		c++;
	copy = malloc(sizeof(char) * (c + 1));
	if (!copy)
		return (0);
	c = 0;
	while (s[c])
	{
		copy[c] = s[c];
		c++;
	}
	copy[c] = '\0';
	return (copy);
}
