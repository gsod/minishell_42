/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:16:33 by mepifano          #+#    #+#             */
/*   Updated: 2023/05/14 15:58:57 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(t_info *info)
{
	int	i;
	int	unset;
	int	j;

	unset = 0;
	i = 1;
	if (!info->space_mat[1])
		return (0);
	while (info->space_mat[i])
	{
		j = 0;
		while (info->myenvp[j])
		{
			if (ft_strncmp(info->myenvp[j], info->space_mat[i], \
					ft_strlen(info->space_mat[i])) == 0)
				aux_unset(info, &j, &unset);
			j++;
		}
		i++;
	}
	if (unset == 0)
		printf("minishell: unset: `%s': not a valid identifier\n", \
				info->space_mat[i - 1]);
	return (0);
}

void	aux_unset(t_info *info, int *j, int *unset)
{
	while (info->myenvp[*j + 1])
	{
		free(info->myenvp[*j]);
		info->myenvp[*j] = ft_strdup(info->myenvp[*j + 1]);
		*j += 1;
	}
	free(info->myenvp[*j]);
	info->myenvp[*j] = NULL;
	free(info->myenvp[*j + 1]);
	*unset = 1;
}
