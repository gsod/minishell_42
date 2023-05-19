/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:00:39 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 15:53:27 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	m;
	size_t	i;
	size_t	z;

	i = 0;
	m = 0;
	z = 0;
	while (src[i] != '\0')
	{
		m++;
		i++;
	}
	if (!dstsize)
	{
		return (m);
	}
	while (src[z] && z < dstsize - 1)
	{
		dst[z] = src[z];
		z++;
	}
	dst[z] = '\0';
	return (m);
}
