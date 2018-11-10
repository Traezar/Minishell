/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:34:54 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/09 14:38:07 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*shell_expand(char *str)
{
	int		len;
	char	*ret;

	len = 0;
	ret = NULL;
	if (*str != '$')
		return (str);
	else
		return (get_variable_value(str + 1));
}

char	*get_variable_value(char *str)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	ret = NULL;
	len = ft_strlen(str);
	while (g_env[++i] != NULL)
	{
		if (ft_strncmp(g_env[i], str, len) == 0)
		{
			ret = ft_strsub(g_env[i], len + 1, ft_strlen(g_env[i]) - (len + 1));
			return (ret);
		}
	}
	return (ft_strdup("\n"));
}

char	**get_path_list(char *pathstr)
{
	char **ret;

	ret = ft_strsplit(pathstr, ':');
	ft_strdel(&pathstr);
	return (ret);
}

void	exit_nfd(char *path)
{
	ft_putstr_fd("Minishell : command not found: ", 2);
	ft_putendl_fd(path, 2);
	return ;
}

void	makepath(char **path, char *args)
{
	char *tmp;
	char *ret;

	if (*args != '/')
	tmp = ft_strjoin(*path, "/");
	else
	tmp = ft_strdup(*path);
	ret = ft_strjoin(tmp, args);
	free(tmp);
	free(*path);
	*path = ret;
	return ;
}
