/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:53:48 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/19 15:45:24 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	no_pipe2(t_info *info, int bob, int j)
{
	if (bob != -1)
	{
		info->exp = expander(info->space_mat[j], bob + 1);
		info->space_mat[j] = sostitution(info, info->space_mat[j], \
											info->exp, bob);
		free(info->exp);
	}
}

void	aux_nopipe1(t_info *info)
{
	info->nopipe = true;
	if (info->redir_fd && info->redir_fd[0][1] != -1)
		dup2(info->redir_fd[0][1], 1);
	if (info->redir_fd && info->redir_fd[0][0] != -1)
		dup2(info->redir_fd[0][0], 0);
	info->space_mat = smartsplit(info->pipe_mat[0], ' ');
}

void	aux_nopipe2(t_info *info, int *j, int *aux, int *flag)
{
	if (info->space_mat[*j][*aux] == '\"')
	{
		if (*flag == 0)
			*flag = 1;
		else
			*flag = 0;
	}
	if (info->space_mat[*j][*aux] == '\'' && *flag == 0)
	{
		*aux += 1;
		while (info->space_mat[*j][*aux] && info->space_mat[*j][*aux] != '\'')
			*aux += 1;
	}
}

void	aux_nopipe3(t_info *info, int *bob, int j, int *tmp)
{
	if (*bob != -1)
	{
		if (info->space_mat[j][*bob + 1] == '?')
		{
			info->exp = ft_itoa(g_exitstatus);
			info->space_mat[j] = sostitution(info, info->space_mat[j], \
										info->exp, *bob);
			free(info->exp);
			*bob = -1;
		}
		*tmp = *bob;
		no_pipe2(info, *bob, j);
	}
}

void	no_pipe(t_info *info, int bob, int j, int tmp)
{
	int	aux;
	int	flag;

	flag = 0;
	aux_nopipe1(info);
	while (info->space_mat[j])
	{
		aux = 0;
		while (info->space_mat[j][aux])
		{
			aux_nopipe2(info, &j, &aux, &flag);
			bob = -1;
			if (info->space_mat[j][aux] == '$')
				bob = aux;
			if (bob != -1 && (info->space_mat[j][bob + 1] == ' ' || \
					info->space_mat[j][bob + 1] == '\0'))
				break ;
			aux_nopipe3(info, &bob, j, &tmp);
			aux++;
		}
		info->space_mat[j] = mytrimmer2(info->space_mat[j]);
		j++;
	}
	g_exitstatus = ft_builtin(info);
	return ;
}
