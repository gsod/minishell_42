/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:48:28 by rpoggi            #+#    #+#             */
/*   Updated: 2022/02/08 15:22:15 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	if (n <= 0 || (!s1 && !s2))
		return (0);
	else
	{
		while ((s1[c] == s2[c] && c < n) && (s1[c] != '\0' && s2[c] != '\0'))
		{
			c++;
		}
		if (c == n)
			c--;
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	}
	return (0);
}
