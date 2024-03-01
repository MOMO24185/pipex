/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/01 13:46:35 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipe_final_cmd(t_file file);

int	main(int argc, char **argv, char **envp)
{
	t_file	file;
	int		status;
	int		count;

	if (argc < 5)
		return (ft_putendl_fd("Usage: file1 cmd1 cmd2... cmdn file2",
				STDERR_FILENO), 0);
	count = 1;
	while (++count < argc - 2)
	{
		file = create_file(argv[1], argv[count], envp, 0);
		if (count == 2)
			dup2(file.fd, 0);
		pipe_cmd(file);
		free_file(file);
	}
	file = create_file(argv[argc - 1], argv[argc - 2], envp, 1);
	if (file.fd >= 0)
		dup2(file.fd, 1);
	status = pipe_final_cmd(file);
	return (free_file(file), status);
}

int	pipe_final_cmd(t_file file)
{
	int		status;
	pid_t	pid;

	status = 0;
	if (file.fd == -1)
		exit_failure(file.name, NULL, file, 1);
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file, 1);
	if (pid == 0)
		execute_cmd(file, NULL);
	else if (waitpid(pid, &status, 0) > 0)
		return (status);
	return (status);
}

/*
POOPOO TO UNPOOP:

-	output of this command is incorrect
./pipex file1 poopoostinky wc file2

 */
