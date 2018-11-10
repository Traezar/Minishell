/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:28:29 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/09 14:38:48 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <sys/stat.h>

void	cd_env_change(char *new_pwd)
{
	char	*str;
	char	*tmp;

	str = get_variable_value("PWD");
	tmp = ft_strjoin("OLDPWD=", str);
	update_env_var(tmp);
	ft_strdel(&tmp);
	tmp = ft_strjoin("PWD=", new_pwd);
	update_env_var(tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
}

void	change_home(char *path)
{
	char	*var_str;
	char	*full_path;

	var_str = get_variable_value("HOME");
	if (path != NULL)
		full_path = ft_char_subst('~', var_str, path);
	else
		full_path = ft_strdup(var_str);
	if (chdir(full_path) != 0){ft_printf("It went into 1\n");
		exit_nfd(full_path);}
	else{ft_printf("It went into 2\n");
		cd_env_change(full_path);}
		ft_printf("It went into clear var\n");
	ft_strdel(&var_str);
	ft_strdel(&full_path);
		ft_printf("It went into clear full_path\n");
}

void	change_previous_dir(void)
{
	char	*var_str;

	var_str = get_variable_value("OLDPWD");
	if (chdir(var_str) != 0)
		ft_putendl_fd("Minishell : Error chdir - : ", 2);
	else
		cd_env_change(var_str);
	ft_strdel(&var_str);
}

int		mini_cd(char **args)
{
	struct stat	buf;

	if (args[1] == NULL || ft_strchr(args[1], '~') != NULL)
		change_home(args[1]);
	else if (ft_strcmp(args[1], "-") == 0)
		change_previous_dir();
	else if (stat(args[1], &buf) == -1)
	{
		ft_putstr_fd("Minishell : no such file or directory: ", 2);
		ft_putendl_fd(args[1], 2);
	}
	else
	{
		if ((buf.st_mode & S_IRWXU) && (chdir(args[1]) == 0))
			cd_env_change(args[1]);
		else
		{
			ft_putstr_fd("Minishell : permission denied : ", 2);
			ft_putendl_fd(args[1], 2);
		}
	}
	return (1);
}
