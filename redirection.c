/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:48 by domy              #+#    #+#             */
/*   Updated: 2023/05/19 15:26:45 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*first_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	word = ft_substr(str, 0, i);
	i = 0;
	while (word[i])
	{
		if (word[i] == '\"' || word[i] == '\'')
			word[i] = ' ';
		i++;
	}
	return (ft_strtrim(word, " "));
}

int	output_redir(t_info *info, int i, int j)
{
	int		fd;
	char	*word;

	word = first_word(&info->pipe_mat[i][j + 1]);
	fd = open(word, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (info->redir_fd[i][1] != -1)
		close(info->redir_fd[i][1]);
	info->redir_fd[i][1] = dup(fd);
	free(word);
	close(fd);
	return (0);
}

int	db_output_redir(t_info *info, int i, int j)
{
	int		fd;
	char	*word;

	word = first_word(&info->pipe_mat[i][j + 2]);
	fd = open(word, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (info->redir_fd[i][1] != -1)
		close(info->redir_fd[i][1]);
	info->redir_fd[i][1] = dup(fd);
	free(word);
	close(fd);
	return (0);
}

int	input_redir(t_info *info, int i, int j)
{
	int		fd;
	char	*word;

	word = first_word(&info->pipe_mat[i][j + 1]);
	fd = open(word, O_RDONLY);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", \
			&info->pipe_mat[i][j + 1]);
		free(word);
		return (1);
	}
	if (info->hedoc_fd && info->hedoc_fd[i][0] != -1 \
			&& info->hedoc_fd[i][1] <= j)
	{
		free(word);
		return (0);
	}
	if (info->redir_fd[i][0] != -1)
		close(info->redir_fd[i][0]);
	info->redir_fd[i][0] = dup(fd);
	free(word);
	close(fd);
	return (0);
}

int	redirec(t_info *info, int i, int j)
{
	info->redir_fd = NULL;
	if (aux_redirection2(info, 0, 0) == 1)
		return (1);
	aux_redirection3(info, &i, &j);
	while (info->pipe_mat[i])
	{
		j = 0;
		info->redir_fd[i] = malloc(sizeof(int) * 2);
		info->redir_fd[i][1] = -1;
		if (info->hedoc_fd && info->hedoc_fd[i][0] != -1)
			info->redir_fd[i][0] = dup(info->hedoc_fd[i][0]);
		else
			info->redir_fd[i][0] = -1;
		if (aux_redirection1(info, &i, &j) == 1)
			return (0);
		i++;
	}
	ft_input_rep(info);
	ft_doutput_rep(info, 0, 0);
	output_rep(info, 0);
	return (1);
}
