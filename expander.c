/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:31:11 by dallocca          #+#    #+#             */
/*   Updated: 2023/05/13 19:03:56 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expander(char *str, int i)
{
	char	*ret;
	int		j;
	int		tmp;

	tmp = i;
	j = 0;
	while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') \
						|| (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
	{
		j++;
		i++;
	}
	ret = ft_calloc(j + 1, sizeof(char));
	i = tmp;
	tmp = j;
	j = 0;
	while (tmp > 0)
	{
		ret[j] = str[i];
		j++;
		i++;
		tmp--;
	}
	return (ret);
}

char	*sostitution(t_info *info, char *str, char *exp, int i)
{
	if (str[i + 1] == '?')
		return (aux_exp(info, str, exp, i));
	info->ret_exp = ft_substr(str, 0, i);
	info->tmp_exp = search_in_envp(info->myenvp, exp);
	if (info->tmp_exp == NULL)
		info->tmp_exp = ft_strdup("");
	info->ret_exp = ft_strjoin(info->ret_exp, info->tmp_exp);
	free(info->tmp_exp);
	info->tmp_exp = ft_substr(str, i + ft_strlen(exp) + 1, ft_strlen(str));
	info->ret_exp = ft_strjoin(info->ret_exp, info->tmp_exp);
	free(info->tmp_exp);
	free(str);
	if (!info->ret_exp)
		return (ft_strdup(""));
	return (info->ret_exp);
}

char	*aux_exp(t_info *info, char *str, char *exp, int i)
{
	char	*bob;

	info->ret_exp = ft_substr(str, 0, i);
	info->ret_exp = ft_strjoin(info->ret_exp, exp);
	info->tmp_exp = ft_substr(str, i + 2, ft_strlen(str) - (i + 2));
	info->ret_exp = ft_strjoin(info->ret_exp, info->tmp_exp);
	free(info->tmp_exp);
	free(str);
	bob = info->ret_exp;
	return (bob);
}
