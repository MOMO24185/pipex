/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:50 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/21 17:36:18 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "string.h"

int	pipe_cmd(t_file file)
{
	int		my_pipes[2];
	pid_t	pid;

	if (pipe(my_pipes) == -1)
		exit_failure(POOPOO_PIPE, free_file, file, 1);
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file, 1);
	if (pid == 0)
		call_child(file, my_pipes);
	else if (pid > 0 && wait(&status) >= 0)
	{
		close(my_pipes[1]);
		dup2(my_pipes[0], 0);
	}
	return (pid);
}

void	call_child(t_file file, int my_pipes[2])
{
	close(my_pipes[0]);
	dup2(my_pipes[1], 1);
	execute_cmd(file);
}

void	execute_cmd(t_file file)
{
	execve(file.path, file.args, file.envp);
	exit_failure(file.args[0], free_file, file, 0);
}

void	exit_failure(char *str, void (*f)(t_file), t_file file, int exit_option)
{
	ft_putnbr_fd(errno, STDERR_FILENO);
	ft_putstr_fd("\x1b[31mpipex: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("\x1b[0m", STDERR_FILENO);
	if (exit_option == 1)
	{
		if (f && file.fd >= 0)
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
