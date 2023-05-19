/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:42:52 by rpoggi            #+#    #+#             */
/*   Updated: 2023/05/14 17:44:34 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exitstatus;

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

void	ft_shlvl(t_info *info)
{
	int		shlvl;
	char	*str;
	char	*tmp;

	str = search_in_envp(info->myenvp, "SHLVL");
	if (!str)
		return ;
	shlvl = ft_atoi(str);
	shlvl++;
	tmp = ft_itoa(shlvl);
	info->space_mat = ft_calloc(3, sizeof(char *));
	info->space_mat[0] = ft_strdup("export");
	info->space_mat[1] = ft_strdup("SHLVL=");
	info->space_mat[1] = ft_strjoin(info->space_mat[1], tmp);
	ft_export(info);
	free(tmp);
	free(str);
	free_mat(info->space_mat);
}

void	main_while(t_info *info)
{
	int	z;

	while (info->myexit != true)
	{
		z = 0;
		info->input = readline("minishell$: ");
		if (info->input == NULL)
			break ;
		info->input = ft_strtrim(info->input, " ");
		z = main_while_aux(info, z);
		if (z == 1000)
			continue ;
		if (z == 1)
		{
			free(info->input);
			continue ;
		}
		if (ft_strlen(info->input) != 0)
			display_prompt(info);
		free_int(info->hedoc_fd, info);
		free_int(info->redir_fd, info);
		free_mat(info->pipe_mat);
		free(info->input);
	}
}

int	main_while_aux(t_info *info, int z)
{
	if (ft_strlen(info->input) == 0)
	{
		free(info->input);
		z = 1000;
		return (z);
	}
	if (check_input_ap(info) == 1 || check_input_pipe(info, 0) == 1 || \
		check_input_red(info, 0) == 1)
	{
		z = 1;
		g_exitstatus = 127;
	}
	if (ft_strlen(info->input) != 0)
		add_history(info->input);
	return (z);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	(void)argc;
	(void)argv;
	info.myenvp = envp_cop(envp);
	g_exitstatus = 0;
	info.myexit = false;
	info.std_in_copy = dup(0);
	info.std_out_copy = dup(1);
	info.flag = 0;
	ft_ctrlc(envp);
	ft_signal();
	ft_shlvl(&info);
	main_while(&info);
	printf("exit\n");
	free_mat(info.myenvp);
	clear_history();
	return (g_exitstatus);
}
