/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:50 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/12 15:28:16 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_cmd(t_file file)
{
	int		my_pipes[2];
	pid_t	pid;

	if (pipe(my_pipes) == -1)
		exit_failure(POOPOO_PIPE, free_file, file);
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file);
	if (pid == 0)
		call_child(file, my_pipes);
	else if (pid > 0 && wait(NULL) >= 0)
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
	exit_failure(POOPOO_EXEC, free_file, file);
}

void	exit_failure(char *str, void (*f)(t_file), t_file file)
{
	if (f)
		f(file);
	perror(str);
	exit(EXIT_FAILURE);
}