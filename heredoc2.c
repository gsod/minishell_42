/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:12:52 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 17:55:41 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_aux5(t_info *info, int i, int *j)
{
	info->hedoc_fd[i][1] = *j;
	while (info->pipe_mat[i][*j + 2] == ' ')
		*j += 1;
}

void	heredoc_aux4(t_info *info, int *i, int *j)
{
	while (info->pipe_mat[*i])
		*i += 1;
	info->hedoc_fd = malloc(sizeof(int *) * (*i));
	*i = 0;
	*j = 0;
}

void	heredoc_aux3(t_info *info, int j, int i, int *c)
{
	pipe(c);
	j = 0;
	info->hedoc_fd[i] = malloc(sizeof(int) * 2);
	info->hedoc_fd[i][0] = -1;
	info->hedoc_fd[i][1] = -1;
}

void	heredoc_aux2(t_info *info, int j, int i, int *c)
{
	info->end_word_hedoc = j + 2;
	while (info->pipe_mat[i][info->end_word_hedoc] != ' ')
		info->end_word_hedoc++;
	info->delim = ft_substr(info->pipe_mat[i], \
						j + 2, info->end_word_hedoc - j - 2);
	info->line = readline("> ");
	while (ft_strcmp(info->line, info->delim) != 0)
	{
		if (info->line)
		{
			write(c[1], info->line, ft_strlen(info->line));
			write(c[1], "\n", 1);
		}
		free(info->line);
		info->line = readline("> ");
	}
	free(info->line);
	free(info->delim);
	close(c[1]);
	info->hedoc_fd[i][0] = dup(c[0]);
	close(c[0]);
	ft_delim_rep(info, 0);
}
