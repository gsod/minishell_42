/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:18:03 by mepifano          #+#    #+#             */
/*   Updated: 2023/05/14 15:59:38 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_add_variable(t_info *info, int i, char *key, int j)
{
	while (info->myenvp[i])
	{
		if (ft_strncmp(info->myenvp[i], key, ft_strlen(key)) == 0)
		{
			if (ft_mystrchr(info->myenvp[i], '=') != -1 && \
				ft_mystrchr(info->space_mat[j], '=') == -1)
			{
				free(key);
				return (0);
			}
			free(info->myenvp[i]);
			info->myenvp[i] = ft_strdup(info->space_mat[j]);
			free(key);
			return (0);
		}
		i++;
	}
	return (1);
}
