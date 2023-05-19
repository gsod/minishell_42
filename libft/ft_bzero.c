/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:55:27 by dallocca          #+#    #+#             */
/*   Updated: 2023/03/27 14:56:02 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	z;

	i = n;
	z = 0;
	if (n == 0)
	{
		return ;
	}
	else
	{
		while (i != 0)
		{
			*(char *)(s + z) = 0;
			i--;
			z++;
		}
	}
}