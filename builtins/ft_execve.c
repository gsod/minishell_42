/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:27 by mepifano          #+#    #+#             */
/*   Updated: 2023/05/14 17:59:21 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*aux_execve(t_info *info, int *j)
{
	struct stat	file_stat;
	char		*str;

	str = NULL;
	*j = stat(info->space_mat[0], &file_stat);
	if (S_ISDIR(file_stat.st_mode) && *j == 0)
	{
		write(2, "minishell: ", 12);
		write(2, info->space_mat[0], ft_strlen(info->space_mat[0]));
		write(2, ": is a directory\n", 18);
		return ("PORCODIO");
	}
	if (ft_mystrchr(info->space_mat[0], '/') != -1)
	{
		str = ft_strdup(info->space_mat[0]);
		if (access(str, R_OK) != 0)
		{
			free(str);
			str = NULL;
		}
	}
	info->path = ft_path(search_in_envp(info->myenvp, "PATH"));
	return (str);
}

int	ft_execve(t_info *info, int i, int j, int status)
{
	char		*str;
	pid_t		pid;
	int			return_value;

	str = NULL;
	str = aux_execve(info, &j);
	if (str && strcmp(str, "PORCODIO") == 0)
		return (126);
	if (!str && !info->path)
		return (aux_execve4(info));
	i = 0;
	while (!str && info->path[i])
	{
		str = ft_strdup(info->path[i]);
		str = ft_strjoin(str, info->space_mat[0]);
		if (access(str, R_OK) == 0)
			break ;
		free(str);
		str = NULL;
		i++;
	}
	return_value = aux_execve2(info, str, status, &pid);
	return (return_value);
}

int	aux_execve4(t_info *info)
{
	write(2, "minishell: ", 12);
	write(2, info->space_mat[0], ft_strlen(info->space_mat[0]));
	write(2, ": command not found\n", 21);
	if (info->path)
		free_mat(info->path);
	return (127);
}

int	aux_execve2(t_info *info, char *str, int status, pid_t *pid)
{
	if (str)
	{
		*pid = fork();
		if (*pid == 0)
		{
			execve(str, info->space_mat, info->myenvp);
			exit(errno);
		}
		waitpid(*pid, &status, 0);
		free(str);
		if (info->path)
			free_mat(info->path);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
				return (1);
		}
	}	
	else
		return (aux_execve3(info, str));
	return (0);
}

int	aux_execve3(t_info *info, char *str)
{
	write(2, "minishell: ", 12);
	write(2, info->space_mat[0], ft_strlen(info->space_mat[0]));
	write(2, ": command not found\n", 21);
	free(str);
	if (info->path)
		free_mat(info->path);
	return (127);
}
