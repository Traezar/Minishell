/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:27:01 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/09 14:37:46 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	**init_env(char **environ)
{
	int		i;
	char	**envp;

	i = -1;
	if (!(envp = (char **)malloc(sizeof(char *) *
					(ft_getarraylen(environ) + 1))))
	{
		ft_putendl_fd("Error allocating inital memory for env", 2);
		exit(EXIT_FAILURE);
	}
	while (environ[++i] != NULL)
		envp[i] = ft_strdup(environ[i]);
	envp[i] = NULL;
	return (envp);
}

void	create_or_update_env(char *var)
{
	char	*v_name;
	int		i;

	i = 0;
	v_name = ft_strsub(var, 0, ft_strchr(var, '=') - var);
	while (g_env[i] && ft_strncmp(v_name, g_env[i], ft_strlen(v_name)) != 0)
		i++;
	ft_strdel(&v_name);
	if (g_env[i] != NULL)
		return (update_env_var(var));
	else
		return (add_env_var(var));
}

void	update_env_var(char *var)
{
	char	*v_name;
	int		i;

	i = 0;
	v_name = ft_strsub(var, 0, ft_strchr(var, '=') - var);
	while (g_env[i] && ft_strncmp(v_name, g_env[i], ft_strlen(v_name)) != 0)
		i++;
	ft_strdel(&v_name);
	if (g_env[i] != NULL)
	{
		ft_strdel(&g_env[i]);
		g_env[i] = ft_strdup(var);
	}
	else
		add_env_var(var);
	return ;
}

void	add_env_var(char *var)
{
	int		i;
	char	**ret;

	i = -1;
	ret = (char **)malloc(sizeof(char *) * (ft_getarraylen(g_env) + 2));
	while (g_env[++i] != NULL)
		ret[i] = ft_strdup(g_env[i]);
	ret[i] = ft_strdup(var);
	i++;
	ret[i] = NULL;
	if (g_env != NULL)
		ft_free_dblarray(&g_env);
	g_env = ret;
	return ;
}
