/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:54:42 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/19 15:19:22 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(t_info *info)
{
	int		i;
	int		j;
	int		bob;
	int		tmp;

	i = 0;
	j = 0;
	bob = 0;
	tmp = 0;
	aux_display2(info);
	while (info->pipe_mat[info->num_com])
		info->num_com++;
	heredoc(info, 0, 0);
	if (aux_display(info, bob, j, tmp) == 1)
		return ;
	while (info->pipe_mat[i])
	{
		yes_pipe(info, i, bob, tmp);
		i++;
		free_mat(info->space_mat);
	}
	i = 0;
	waitpid(info->pid_display, &info->status, 0);
	display_prompt2(info, i);
}

void	aux_display2(t_info *info)
{
	info->num_com = 0;
	info->mystd_in = -1;
	info->pipe_mat = smartsplit(info->input, '|');
}

int	aux_display(t_info *info, int bob, int j, int tmp)
{
	if (redirec(info, 0, 0) == 0)
	{
		g_exitstatus = 1;
		return (1);
	}
	if (checker_space(info) == 1)
	{
		g_exitstatus = 0;
		return (1);
	}
	if (info->pipe_mat[1] == NULL)
	{
		no_pipe(info, bob, j, tmp);
		dup2(info->std_in_copy, 0);
		dup2(info->std_out_copy, 1);
		free_mat(info->space_mat);
		return (1);
	}
	return (0);
}

void	display_prompt2(t_info *info, int i)
{
	while (info->pipe_mat[i + 1])
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	if (WIFEXITED(info->status))
		g_exitstatus = WEXITSTATUS(info->status);
	dup2(info->std_in_copy, 0);
	dup2(info->std_out_copy, 1);
	close(info->mystd_in);
}

int	checker_space(t_info *info)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (info->pipe_mat[i])
	{
		j = 0;
		while (info->pipe_mat[i][j] >= 33 && info->pipe_mat[i][j] <= 126)
		{
			z++;
			j++;
		}
		if (z == 0)
			return (1);
		i++;
	}
	return (0);
}
