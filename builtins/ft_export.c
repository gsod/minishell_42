/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:48 by rpoggi            #+#    #+#             */
/*   Updated: 2023/05/14 16:48:01 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**envp_cop(char **envp)
{
	int		i;
	char	**cpy;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	cpy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		cpy[i] = ft_strdup(envp[i]);
		i++;
	}
	return (cpy);
}

char	**ft_sort(char **envp)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	while (envp[i + 1])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				cpy = envp[i];
				envp[i] = envp [j];
				envp[j] = cpy;
			}
			j++;
		}
		i++;
	}
	return (envp);
}

int	ft_export(t_info *info)
{
	char	**cpy;
	char	*key;
	int		i;
	int		j;

	key = NULL;
	i = 1;
	j = 0;
	if (!info->space_mat[1])
	{
		cpy = ft_sort(info->myenvp);
		ft_quotes(cpy);
		return (0);
	}
	if (aux_export1(info, i, j) == 1)
		return (1);
	i = 0;
	j = 1;
	aux_export2(info, i, j, key);
	return (0);
}

void	ft_quotes(char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				printf("%c", envp[i][j]);
				printf("\"");
			}
			else
				printf("%c", envp[i][j]);
			j++;
		}
		if (ft_mystrchr(envp[i], '=') != -1)
			printf("\"");
		printf("\n");
		i++;
	}
}

char	**ft_add_envp(t_info *info, char *key, int arg)
{
	char	*value;
	char	**newenv;
	int		i;
	int		j;

	i = 0;
	while (info->myenvp[i])
		i++;
	newenv = calloc(i + 2, sizeof(char *));
	aux_export4(info, newenv, &i);
	newenv[i] = ft_strdup(key);
	j = ft_mystrchr(info->space_mat[arg], '=');
	if (j != -1)
	{
		value = ft_substr(info->space_mat[arg], j + 1, \
							ft_strlen(info->space_mat[arg]) - j + 1);
		value = ft_strtrim(value, "\"");
		newenv[i] = ft_strjoin(newenv[i], "=");
		newenv[i] = ft_strjoin(newenv[i], value);
		free(value);
	}
	free_mat(info->myenvp);
	return (newenv);
}
