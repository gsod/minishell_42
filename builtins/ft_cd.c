/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:08:19 by rpoggi            #+#    #+#             */
/*   Updated: 2023/03/30 14:49:07 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char *args, t_info *info)
{
	char	*env_path;
	int		cd_ret;

	if (!args || (ft_strcmp(args, "~") == 0))
		env_path = search_in_envp(info->myenvp, "HOME");
	else if (ft_strcmp(args, "-") == 0)
		env_path = search_in_envp(info->myenvp, "OLDPWD");
	else
		env_path = ft_strdup(args);
	cd_ret = chdir(env_path);
	if (!env_path || cd_ret < 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", args);
		return (1);
	}
	free (env_path);
	return (0);
}
