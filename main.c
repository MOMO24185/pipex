/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/26 15:25:04 by melshafi         ###   ########.fr       */
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
	dup2(file.fd, 1);
	status = pipe_final_cmd(file);
	return (free_file(file), status);
}

int	pipe_final_cmd(t_file file)
{
	int		my_pipes[2];
	int		status;
	pid_t	pid;

	status = 0;
	if (pipe(my_pipes) == -1)
		exit_failure(POOPOO_PIPE, free_file, file, 1);
	if (file.fd == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		exit_failure(POOPOO_FORK, free_file, file, 1);
	if (pid == 0)
		execute_cmd(file);
	else if (waitpid(pid, &status, WNOHANG) > 0)
		close(my_pipes[1]);
	return (status);
}

/*
POOPOO TO UNPOOP:

-	adjust wait process so that all PIDs run at the same

</dev/urandom cat | cat > outej
./pipex /dev/urandom cat "echo hi" outej

-	program stops at error, it should keep going till it creates file2

-	correct err messages to return appropriate message

-	check if cmd starts "./" in order to search within current dir
otherwise use default paths
 */
