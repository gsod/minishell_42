/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:24:59 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 14:32:49 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_main_aux(t_info *info, int i)
{
	if (info->input[i] == '\0')
	{
		write(2, "minishell: syntax error\n", 25);
		return (1);
	}
	return (0);
}

int	check_input_pipe(t_info *info, int c)
{
	int	i;

	i = 0;
	while (info->input[i])
	{
		if (info->input[i] == '|')
		{
			if (check_main_while_2(info, i) == 1)
				return (1);
			i++;
			c = 0;
			while (info->input && info->input[i] == ' ')
				i++;
			check_main_while_3(info, &i, &c);
			if (info->input[i] == '|')
				i--;
			if (c == 0)
			{
				write(2, "minishell: syntax error\n", 25);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_input_ap(t_info *info)
{
	int	i;

	i = 0;
	while (info->input[i])
	{
		if (info->input[i] == '\'')
		{
			i++;
			while (info->input[i] != '\'' && info->input[i] != '\0')
				i++;
			if (check_main_aux(info, i) == 1)
				return (1);
		}
		if (info->input[i] == '\"')
		{
			i++;
			while (info->input[i] != '\"' && info->input[i] != '\0')
				i++;
			if (check_main_aux(info, i) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
