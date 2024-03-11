/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/11 14:41:01 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipe_final_cmd(t_file file);

int	main(int argc, char **argv, char **envp)
{
	t_file	file;
	int		count;

	if (argc != 5)
		return (ft_putendl_fd(POOPOO_USAGE, STDERR_FILENO), 0);
	count = 1;
	while (++count < argc - 2)
	{
		if (argv[count])
		{
			file = create_file(argv[1], argv[count], envp, O_RDONLY);
			if (count == 2)
			{
				dup2(file.fd, 0);
				pipe_cmd(file, 1);
			}
			else
				pipe_cmd(file, 0);
			free_file(file);
		}
	}
	file = create_file(argv[argc - 1], argv[argc - 2], envp, O_CREAT | O_WRONLY
			| O_TRUNC);
	return (pipe_final_cmd(file));
}

int	pipe_final_cmd(t_file file)
{
	int		status;
	pid_t	pid;

	status = 0;
	if (file.fd >= 0)
		dup2(file.fd, 1);
	else
		exit_failure(file.name, NULL, file, 1);
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file, 1);
	if (pid == 0 && file.path)
		execute_cmd(file, NULL);
	else if (waitpid(pid, &status, 0) > 0)
	{
		free_file(file);
		return (status);
	}
	free_file(file);
	return (status);
}

/*
POOPOO TO UNPOOP:

-close FDs

 */
