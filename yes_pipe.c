/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yes_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:52:25 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 14:51:27 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	yes_pipe7(t_info *info, int i)
{
	close(info->pipes[0]);
	if (info->hedoc_fd)
		close(info->hedoc_fd[i][0]);
	if (info->redir_fd && info->redir_fd[i][1] == -1 && info->pipe_mat[i + 1])
		dup2(info->pipes[1], 1);
}

void	yes_pipe6(t_info *info, int bob, int j, int tmp)
{
	(void)tmp;
	if (bob != -1)
	{
		info->exp = expander(info->space_mat[j], bob + 1);
		info->space_mat[j] = sostitution(info, info->space_mat[j], \
									info->exp, bob);
		free(info->exp);
	}
}

void	yes_pipe5(t_info *info, int i)
{
	pipe(info->pipes);
	info->space_mat = smartsplit(info->pipe_mat[i], ' ');
	info->pid_display = fork();
}

void	yes_pipe4(t_info *info, int i)
{
	if (info->mystd_in != -1)
		close(info->mystd_in);
	info->mystd_in = dup(info->pipes[0]);
	dup2(info->mystd_in, 0);
	close(info->pipes[1]);
	close(info->pipes[0]);
	if (info->hedoc_fd && info->hedoc_fd[i][0] != -1)
		close(info->hedoc_fd[i][0]);
	if (info->hedoc_fd && info->hedoc_fd[i][1] != -1)
		close(info->hedoc_fd[i][1]);
}

void	yes_pipe3(t_info *info)
{
	g_exitstatus = ft_builtin(info);
	close(info->pipes[1]);
	exit(g_exitstatus);
}
