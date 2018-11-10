/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:30:42 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/06 11:15:01 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	remove_env_var(char *var)
{
	int		i;
	char	**envp;

	i = 0;
	if (!(envp = (char **)malloc(ft_getarraylen(g_env) * sizeof(char*))))
	{
		ft_putendl_fd("Error allocating memory for removal of env", 2);
		return (-1);
	}
	while (g_env[i] != NULL && ft_strncmp(var, g_env[i], ft_strlen(var)) != 0)
	{
		envp[i] = ft_strdup(g_env[i]);
		i++;
	}
	while (g_env[++i] != NULL)
		envp[i - 1] = ft_strdup(g_env[i]);
	envp[i - 1] = NULL;
	ft_free_dblarray(&g_env);
	g_env = envp;
	return (1);
}

int	mini_unsetenv(char **args)
{
	int		i;
	int		argcount;

	argcount = 0;
	i = 0;
	while (args[argcount] != NULL)
		argcount++;
	if (argcount != 2)
	{
		ft_putendl_fd("minishell: usage: unsetenv FOO", 1);
		return (-1);
	}
	while (g_env[i] != NULL && ft_strncmp(args[1], g_env[i],
				ft_strlen(args[1])) != 0)
		i++;
	if (g_env[i] == NULL)
		return (1);
	else
		remove_env_var(args[1]);
	return (1);
}
