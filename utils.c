/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:57:29 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/14 14:51:13 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_in_envp(char **envp, char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (envp[i])
	{
		j = 0;
		if (ft_strncmp(envp[i], str, (ft_strlen(str))) == 0 && \
				envp[i][ft_strlen(str)] == '=')
		{
			while (envp[i][j] != '=')
				j++;
			j++;
			ret = ft_strdup(&envp[i][j]);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	if (mat)
		free(mat);
}

void	free_int(int **mat, t_info *info)
{
	int	i;

	i = 0;
	while (mat && i < info->num_com)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
