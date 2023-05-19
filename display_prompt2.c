/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:59:53 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/19 15:44:40 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aux_disp_pr2(t_info *info, int *bob, int *j, int *tmp)
{
	if (info->space_mat[*j][*bob + 1] == '?')
	{
		info->exp = ft_itoa(g_exitstatus);
		info->space_mat[*j] = sostitution(info, info->space_mat[*j], \
									info->exp, *bob);
		free(info->exp);
		*bob = -1;
	}
	*tmp = *bob;
	yes_pipe6(info, *bob, *j, *tmp);
}

void	aux_disp_pr3(t_info *info, int i)
{
	if (info->redir_fd && info->redir_fd[i][1] != -1)
		dup2(info->redir_fd[i][1], 1);
	if (info->redir_fd && info->redir_fd[i][0] != -1)
		dup2(info->redir_fd[i][0], 0);
}

void	aux_disp_pr4(t_info *info, int *j, int *bob, int *tmp)
{
	while (info->space_mat[*j][info->disp_aux])
	{
		aux_disp_pr(info, *j, bob);
		if (*bob != -1 && (info->space_mat[*j][*bob + 1] == ' ' || \
				info->space_mat[*j][*bob + 1] == '\0'))
			break ;
		if (*bob != -1)
			aux_disp_pr2(info, bob, j, tmp);
		info->disp_aux++;
	}
}

void	aux_disp_pr(t_info *info, int j, int *bob)
{
	if (info->space_mat[j][info->disp_aux] == '\"')
	{
		if (info->disp_flag == 0)
			info->disp_flag = 1;
		else
			info->disp_flag = 0;
	}
	if (info->space_mat[j][info->disp_aux] == '\'' && info->disp_flag == 0)
	{
		info->disp_aux += 1;
		while (info->space_mat[j][info->disp_aux] && \
				info->space_mat[j][info->disp_aux] != '\'')
			info->disp_aux += 1;
	}
	*bob = -1;
	if (info->space_mat[j][info->disp_aux] == '$')
		*bob = info->disp_aux;
}
