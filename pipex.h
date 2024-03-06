/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:56:17 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/06 10:59:09 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

#include <stdio.h>

# define POOPOO_USAGE "Usage: file1 cmd1 cmd2 ... cmdn file2"
# define POOPOO_PIPE "PIPE Failed"
# define POOPOO_FORK "FORK Failed"
# define POOPOO_OPEN "OPEN Failed"
# define POOPOO_EXEC "Command may not be available"
# define POOPOO_ACCESS "ACCESS Failed"
# define POOPOO_CMD "Invalid command"

typedef struct s_file
{
	int		fd;
	char	*name;
	char	*path;
	char	**args;
	char	**envp;
}	t_file;

/***************************/
/*     pipex functions     */
/***************************/
//Parses through the arguments and handles function calls
//for setting up the shell commands, piping and forking.
int		pipe_cmd(t_file file);
void	call_child(t_file file, int my_pipes[2]);
void	execute_cmd(t_file file, int *my_pipes);

/***************************/
/*     pipex_file_utils    */
/***************************/
//Returns a list of all the possible paths for our command
char	*get_all_paths(char **envp, char *var);
//Finds environment path for the command and returns it
char	*get_path(char **envp, char *cmd, char *var);
//Creates new file with full permissions, returns FD to that file
t_file	create_file(char *name, char *args, char **envp, int mode);
//Joins 2 types (char *) strings, assumes first has been malloced and attempts
//to free it.
//If you have no need for free handling first parameter then use ft_strjoin
char	*join_strs(char *str, char *buffer);
//Frees content of 2 t_file types
void	free_file(t_file file);
//Exits programm with given param string, and prints error message
//according to the current errno
void	exit_failure(char *str, void (*f)(t_file), t_file file, int exit_option);
//Free 2d char
void	free_2dchar(char **str);
//Checks for pipe content to wait for command execution or not
void	check_pipe(int *pipe_fd, int pid, char *cmd);
//Reads using gnl till gnl returns null
char	*gnl_till_null(int *pipe_fd, char *str);

/***************************/
/*     Other functions     */
/***************************/
//Compares 2 strings
int		ft_strcmp(char *s1, char *s2);
#endif
