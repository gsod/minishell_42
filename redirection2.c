/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:35:34 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/19 15:43:42 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aux_redirection4(t_info *info, int i, int *j)
{
	while (*j > -1 && info->pipe_mat[i][*j] != '\"' && \
			info->pipe_mat[i][*j] != '\'' && info->pipe_mat[i][*j])
		*j -= 1;
}

int	aux_redirection2(t_info *info, int i, int j)
{
	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '>' || info->pipe_mat[i][j] == '<')
			{
				if (info->pipe_mat[i][j] == '>' && \
					info->pipe_mat[i][j + 1] == '>')
					j++;
				aux_redirection4(info, i, &j);
				if (j == -1)
					break ;
				if (j != -1)
				{
					info->flag = 1;
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	aux_redirection1(t_info *info, int *i, int *j)
{
	while (info->pipe_mat[*i][*j])
	{
		if (info->pipe_mat[*i][*j] == '>' && info->pipe_mat[*i][*j + 1] == '>')
		{
			db_output_redir(info, *i, *j);
			*j += 2;
			continue ;
		}
		else if (info->pipe_mat[*i][*j] == '>')
		{
			output_redir(info, *i, *j);
			*j += 1;
			continue ;
		}
		else if (info->pipe_mat[*i][*j] == '<')
			if (input_redir(info, *i, *j) == 1)
				return (1);
		*j += 1;
	}
	return (0);
}

void	aux_redirection3(t_info *info, int *i, int *j)
{
	while (info->pipe_mat[*i])
		*i += 1;
	info->redir_fd = malloc(sizeof(int *) * (*i + 1));
	*i = 0;
	*j = 0;
}
