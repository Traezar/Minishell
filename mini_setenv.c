/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:30:22 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/06 11:11:13 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	mini_setenv(char **args)
{
	char	*equal_pointer;
	int		argcount;

	argcount = 0;
	equal_pointer = NULL;
	while (args[argcount] != NULL)
		argcount++;
	if (argcount != 2)
	{
		ft_putendl_fd("minishell: usage: setenv FOO=bar", 1);
		return (-1);
	}
	equal_pointer = ft_strchr(args[1], '=');
	if (equal_pointer != NULL && ((equal_pointer + 1) != '\0'))
		create_or_update_env(args[1]);
	else
	{
		ft_putendl_fd("minishell: usage: setenv FOO=bar", 1);
		return (-1);
	}
	return (1);
}
