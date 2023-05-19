/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:40 by rpoggi            #+#    #+#             */
/*   Updated: 2023/05/14 16:27:41 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(t_info *info)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (info->space_mat[i] && ft_strcmp(info->space_mat[i], "-n") == 0)
	{
			i++;
			n_flag = 1;
	}
	while (info->space_mat[i])
	{
		if (n_flag == 1 && i == 1)
			i++;
		else
		{
			printf("%s", info->space_mat[i]);
			if (info->space_mat[i + 1])
				printf(" ");
			i++;
		}
	}
	if (n_flag == 0)
		printf("\n");
	return (0);
}
