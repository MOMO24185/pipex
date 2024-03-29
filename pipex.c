/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:50 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/11 14:17:17 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_cmd(t_file file, int flags, int *my_pipes)
{
	pid_t	pid;
	char	*str;

	str = NULL;
	if (flags == 1 && file.fd == -1)
		exit_failure(POOPOO_FILE, NULL, file, -1);
	if (flags == 1)
		dup2(file.fd, 0);
	if (!file.path)
	{
		str = gnl_till_null(my_pipes, str);
		close(my_pipes[1]);
		dup2(my_pipes[0], 0);
		return (free_file(file), free(str), 0);
	}
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file, 1);
	if (pid == 0)
		call_child(file, my_pipes);
	check_pipe(pid, file.path);
	return (close(my_pipes[1]), dup2(my_pipes[0], 0), free_file(file), pid);
}

void	call_child(t_file file, int *my_pipes)
{
	close(my_pipes[0]);
	dup2(my_pipes[1], 1);
	execute_cmd(file, my_pipes);
}

void	execute_cmd(t_file file, int *my_pipes)
{
	char	*str;

	str = NULL;
	if (file.path)
		execve(file.path, file.args, file.envp);
	if (my_pipes != NULL)
	{
		str = gnl_till_null(my_pipes, str);
		free(str);
	}
	exit_failure(POOPOO_EXEC, free_file, file, 1);
}

void	exit_failure(char *str, void (*f)(t_file), t_file file, int exit_option)
{
	if (exit_option == -2)
		errno = 1;
	ft_putstr_fd("\x1b[31mpipex: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("\x1b[0m", STDERR_FILENO);
	if (exit_option == 1)
	{
		if (f)
			f(file);
		exit(EXIT_FAILURE);
	}
}

void	free_file(t_file file)
{
	if (file.fd >= 0)
	{
		free_2dchar(file.args);
		free(file.path);
		close(file.fd);
	}
}
