/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:29:01 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 19:18:09 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		mini_echo(char **args)
{
	char	*expa;
	int		i;

	i = 0;
	expa = NULL;
	if (args[1] == NULL)
		ft_putstr_fd("\n", 2);
	while (args[++i] != NULL)
	{
		if (args[i][0] == '$')
		{
			expa = shell_expand(args[i]);
			ft_putstr_fd(expa, 1);
			ft_strdel(&expa);
		}
		else
			ft_putstr_fd(args[i], 1);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('\n', 1);
	}
	return (1);
}
