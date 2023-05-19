/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:36:19 by dallocca          #+#    #+#             */
/*   Updated: 2023/03/30 16:05:31 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit(char **input, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->myexit = true;
	if (input[1])
	{
		while (input[1][i])
		{
			if (input[1][i] < '0' || input[1][i] > '9')
			{
				write(2, "minishell: exit: ", 18);
				write(2, input[1], ft_strlen(input[1]));
				write(2, ": numeric argument required\n", 28);
				return (255);
			}
			i++;
		}
		j = ft_atoi(input[1]);
		return (j % 256);
	}
	return (g_exitstatus);
}
