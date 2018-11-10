/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:29:56 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/09 14:40:31 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <sys/stat.h>

int		mini_env(char **args)
{
	int	i;

	i = -1;
	(void)(args);
	while (g_env[++i] != NULL)
		ft_putendl_fd(g_env[i], 1);
	return (1);
}

int		check_path_and_execute(char **patharr, char **args)
{
	int			i;
	struct stat	buf;
	char		**array;
	int			check;

	i = -1;
	array = patharr;
	check = 0;
	while (patharr[++i] != NULL && check == 0)
	{
		if (stat(args[0], &buf) == 0)
			check = execute_prog(args[0], args);
		else
		{
			makepath(&patharr[i], args[0]);
			if (stat(patharr[i], &buf) == 0)
				check = execute_prog(patharr[i], args);
		}
	}
	if (!check)
		exit_nfd(args[0]);
	if (patharr)
	ft_free_dblarray(&patharr);
	return (1);
}
