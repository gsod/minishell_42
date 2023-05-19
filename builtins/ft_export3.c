/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:26:05 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 16:48:34 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	aux_export2(t_info *info, int i, int j, char *key)
{
	while (info->space_mat[j])
	{
		i = ft_mystrchr(info->space_mat[j], '=');
		key = ft_substr(info->space_mat[j], 0, i);
		i = 0;
		if (!ft_add_variable(info, i, key, j))
		{
			j++;
			continue ;
		}
		info->myenvp = ft_add_envp(info, key, j);
		free(key);
		j++;
	}
}

int	aux_export1(t_info *info, int i, int j)
{
	while (info->space_mat[i])
	{
		j = 1;
		if ((info->space_mat[i][0] < 'a' || info->space_mat[i][0] > 'z') && \
			(info->space_mat[i][0] < 'A' || info->space_mat[i][0] > 'Z') && \
			info->space_mat[i][0] != '_')
		{
			write(2, "minishell: ", 12);
			write(2, info->space_mat[i], ft_strlen(info->space_mat[i]));
			write(2, ": not a valid identifier\n", 26);
			return (1);
		}
		while (info->space_mat[i][j] && info->space_mat[i][j] != '=')
		{
			if (aux_export3(info, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	aux_export3(t_info *info, int i, int j)
{
	if ((info->space_mat[i][j] < 'a' || info->space_mat[i][j] > 'z') && \
		(info->space_mat[i][j] < 'A' || info->space_mat[i][j] > 'Z') && \
		(info->space_mat[i][j] < '0' || info->space_mat[i][j] > '9') && \
		info->space_mat[i][j] != '_')
	{
		write(2, "minishell: ", 12);
		write(2, info->space_mat[i], ft_strlen(info->space_mat[i]));
		write(2, ": not a valid identifier\n", 26);
		return (1);
	}
	return (0);
}

void	aux_export4(t_info *info, char **newenv, int *i)
{
	*i = 0;
	while (info->myenvp[*i])
	{
		newenv[*i] = ft_strdup(info->myenvp[*i]);
		*i += 1;
	}
}
