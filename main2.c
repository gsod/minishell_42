/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:23:58 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 14:31:52 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_main_while_3(t_info *info, int *i, int *c)
{
	while ((info->input[*i] >= 33 && info->input[*i] <= 126) && \
			info->input[*i] != '|')
	{
		*c += 1;
		*i += 1;
	}
}

int	check_main_while_2(t_info *info, int i)
{
	if (info->input[i + 1] == '|')
	{
		write(2, "minishell: syntax error\n", 25);
		return (1);
	}
	if (info->input[i + 1] == '\0')
	{
		write(2, "minishell: syntax error\n", 25);
		return (1);
	}
	return (0);
}

int	check_input_red(t_info *info, int c)
{
	int	i;

	i = 0;
	while (info->input[i])
	{
		if ((info->input[i] == '>' && info->input[i + 1] == '>') || \
			(info->input[i] == '<' && info->input[i + 1] == '<'))
		{
			i++;
			if (info->input[i + 1] == '>' || info->input[i + 1] == '<')
			{
				write(2, "minishell: syntax error\n", 25);
				return (1);
			}
		}
		if (info->input[i] == '<' || info->input[i] == '>')
		{
			check_input_red3(info, &i, &c);
			if (check_input_red2(c) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_input_red2(int c)
{
	if (c == 0)
	{
		write(2, "minishell: syntax error\n", 25);
		return (1);
	}
	return (0);
}

void	check_input_red3(t_info *info, int *i, int *c)
{
	*i += 1;
	*c = 0;
	while (info->input[*i] >= 32 && info->input[*i] <= 126)
	{
		*c += 1;
		*i += 1;
	}
}
