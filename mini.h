/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:45:04 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 21:13:32 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "libft/includes/libft.h"
# define BUFFER_SIZE 1024

struct	s_builtin
{
	char	*name;
	int		(*f)(char**);
};

char	**g_env;
char	**g_vlist;

void	shell_loop(void);
char	**get_args_line(char *line);
int		execute_prog(char *path, char **args);
int		execute_args(char **args);
int		mini_cd(char **args);
int		mini_echo(char **args);
int		mini_exit(char **args);
int		mini_setenv(char **args);
int		mini_unsetenv(char **args);
int		mini_env(char **args);
int		num_builtins(void);
char	*shell_expand(char *str);
char	*get_variable_value(char *str);
char	**get_path_list(char *pathstr);
void	makepath(char **path, char *args);
int		check_path_and_execute(char **patharr, char **args);
void	exit_nfd(char *path);
char	**init_env(char **environ);
void	create_or_update_env(char *var);
void	update_env_var(char *var);
void	add_env_var(char *var);
#endif
