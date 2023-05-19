/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:13:29 by rpoggi            #+#    #+#             */
/*   Updated: 2022/02/08 15:13:06 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	c;

	c = 0;
	if (!dest && !src)
		return (0);
	while (c < n)
	{
		((char *)dest)[c] = ((char *)src)[c];
		c++;
	}
	return ((char *)dest);
}
