/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:18:27 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/09 14:39:35 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <sys/stat.h>

struct s_builtin g_bin_array[] = {
	{"cd", &mini_cd},
	{"echo", &mini_echo},
	{"env", &mini_env},
	{"setenv", &mini_setenv},
	{"unsetenv", &mini_unsetenv},
	{"exit", &mini_exit},
};

void	shell_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		get_next_line(1, &line);
		args = get_args_line(line);
		status = execute_args(args);
		ft_strdel(&line);
		ft_printf("It went into cleared line\n");
		ft_free_dblarray(&args);
		ft_printf("It went into cleared argsofline\n");
	}
}

char	**get_args_line(char *line)
{
	char	**args;
	int		i;

	args = NULL;
	i = 0;
	args = ft_split_args_in_line(line);
	return (args);
}

int		execute_prog(char *path, char **args)
{
	pid_t	cpid;
	pid_t	ppid;
	int		status;

	status = 1;
	cpid = fork();
	if (cpid == 0)
	{
		if (execve(path, args, g_env) == -1)
			return (0);
	}
	else if (cpid == -1)
		exit(EXIT_FAILURE);
	else
	{
		ppid = waitpid(cpid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			ppid = waitpid(cpid, &status, WUNTRACED);
	}
	return (1);
}

int		execute_args(char **args)
{
	int		i;
	char	**paths;

	i = -1;
	if (args[0] == NULL || ft_strcmp(args[0],"") == 0 )
		return (1);
	while (++i < 6)
	{
		if (ft_strcmp(args[0], g_bin_array[i].name) == 0)
			return (g_bin_array[i].f(args));
	}
	paths = get_path_list(get_variable_value("PATH"));
	if (i == 6)
		check_path_and_execute(paths, args);
	return (1);
}

int		main(int argc, char **argv, char **environ)
{
	g_env = NULL;
	g_vlist = NULL;
	(void)(argc);
	(void)(argv);
	g_env = init_env(environ);
	shell_loop();
	return (EXIT_SUCCESS);
}
