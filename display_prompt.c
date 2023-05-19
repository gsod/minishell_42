/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/03/28 14:33:5 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_path(char *pathvar)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	if (!pathvar)
		return (NULL);
	matrix = smartsplit(pathvar, ':');
	while (matrix[i])
	{
		j = ft_strlen(matrix[i]);
		matrix[i][j] = '/';
		matrix[i][j + 1] = '\0';
		i++;
	}
	free(pathvar);
	return (matrix);
}

int	ft_execution(char **input, char *bin, char **envp)
{
	pid_t	pid;
	char	*path;

	path = malloc(ft_strlen(bin) + ft_strlen(input[0]) + 1);
	ft_strcpy(path, bin);
	ft_strcat(path, input[0]);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, input, envp) != 0)
			return (1);
	}
	else
	{
		if (wait(NULL) == -1)
			exit(1);
	}
	free(path);
	return (0);
}

void	path_abs(char *input, char **envp)
{
	pid_t	pid;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(input, ' ');
	while (tmp[i])
		i++;
	tmp[i] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(tmp[0], tmp, envp) != 0)
			return ;
	}
	else
	{
		if (wait(NULL) == -1)
			exit(1);
	}
	return ;
}

int	ft_builtin(t_info *info)
{
	int	i;

	i = 0;
	while (info->myenvp[i])
		i++;
	if (ft_strcmp(info->space_mat[0], "cd") == 0)
		return (ft_cd(info->space_mat[1], info));
	else if (ft_strcmp(info->space_mat[0], "echo") == 0)
		return (ft_echo(info));
	else if (ft_strcmp(info->space_mat[0], "exit") == 0)
		return (ft_exit(info->space_mat, info));
	else if (ft_strcmp(info->space_mat[0], "env") == 0)
		return (ft_env(info->myenvp));
	else if (ft_strcmp(info->space_mat[0], "export") == 0)
		return (ft_export(info));
	else if (ft_strcmp(info->space_mat[0], "unset") == 0)
		return (ft_unset(info));
	else
		return (ft_execve(info, 0, 0, 0));
	return (0);
}

void	yes_pipe(t_info *info, int i, int bob, int tmp)
{
	int	j;

	j = 0;
	aux_disp_pr3(info, i);
	yes_pipe5(info, i);
	if (info->pid_display == 0)
	{
		yes_pipe7(info, i);
		while (info->space_mat[j])
		{
			info->disp_aux = 0;
			aux_disp_pr4(info, &j, &bob, &tmp);
			info->space_mat[j] = mytrimmer2(info->space_mat[j]);
			j++;
		}
		yes_pipe3(info);
	}
	info->yespipe = true;
	yes_pipe4(info, i);
	dup2(info->std_out_copy, 1);
}
