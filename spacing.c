/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:54:50 by domy              #+#    #+#             */
/*   Updated: 2023/05/14 14:50:48 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_space_replace(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->pipe_mat[i])
	{
		while (info->pipe_mat[i][j] && info->pipe_mat[i][j] != ' ')
		{
			if (info->pipe_mat[i][j] == '<' && info->pipe_mat[i][j + 1] == '<')
			{
				while (info->pipe_mat[i][j] == ' ')
					j++;
				while (ft_isalnum(info->pipe_mat[i][j]))
				{
					info->pipe_mat[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_doutput_rep(t_info *info, int i, int j)
{
	while (info->pipe_mat[i])
	{
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '>' && info->pipe_mat[i][j + 1] == '>')
			{
				info->pipe_mat[i][j] = ' ';
				info->pipe_mat[i][j + 1] = ' ';
				j += 2;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] == ' ')
					j++;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] != ' ')
				{
					info->pipe_mat[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_input_rep(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '<')
			{
				info->pipe_mat[i][j] = ' ';
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] == ' ')
					j++;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] != ' ')
				{
					info->pipe_mat[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	output_rep(t_info *info, int i)
{
	int	j;

	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '>')
			{
				info->pipe_mat[i][j] = ' ';
				j++;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] == ' ')
					j++;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] != ' ')
				{
					info->pipe_mat[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_delim_rep(t_info *info, int i)
{
	int	j;

	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '<' && info->pipe_mat[i][j + 1] == '<')
			{
				info->pipe_mat[i][j] = ' ';
				info->pipe_mat[i][j + 1] = ' ';
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] == ' ')
					j++;
				while (info->pipe_mat[i][j] && info->pipe_mat[i][j] != ' ')
				{
					info->pipe_mat[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
