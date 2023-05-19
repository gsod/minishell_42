/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:45:41 by domy              #+#    #+#             */
/*   Updated: 2023/05/19 15:45:53 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
	|| (c >= '0' && c <= '9'))
	{
		c = ' ';
		return (1);
	}
	else
		return (0);
}

char	*read_heredoc(char *delimiter)
{
	char	*line;
	char	*input;

	input = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
			return (NULL);
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		input = ft_strjoin(input, line);
		input = ft_strjoin(input, "\n");
		free(line);
	}
	free(line);
	return (input);
}

int	heredoc_aux1(t_info *info, int i, int j)
{
	info->hedoc_fd = NULL;
	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '<' && info->pipe_mat[i][j + 1] == '<')
			{
				while (j > -1 && info->pipe_mat[i][j] != '\"' \
						&& info->pipe_mat[i][j] != '\'' && info->pipe_mat[i][j])
					j--;
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

int	heredoc(t_info *info, int i, int j)
{
	int		c[2];

	if (heredoc_aux1(info, 0, 0) == 1)
		return (1);
	heredoc_aux4(info, &i, &j);
	while (info->pipe_mat[i])
	{
		heredoc_aux3(info, j, i, c);
		while (info->pipe_mat[i][j])
		{
			if (info->pipe_mat[i][j] == '<' && info->pipe_mat[i][j + 1] == '<')
			{
				heredoc_aux5(info, i, &j);
				if (info->pipe_mat[i][j] == '\0')
					return (0);
				else
					heredoc_aux2(info, j, i, c);
			}
			j++;
		}
		i++;
	}
	ft_space_replace(info);
	return (0);
}
