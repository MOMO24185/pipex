/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/06 14:13:34 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipe_final_cmd(t_file file);
static t_file	create_final_file(char **argv, int argc, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_file	file;
	int		count;

	if (argc < 5)
		return (ft_putendl_fd(POOPOO_USAGE, STDERR_FILENO), 0);
	count = 1;
	while (++count < argc - 2)
	{
		if (!ft_strcmp(argv[1], "here_doc"))
			limiter_check(argv[count++]);
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
	file = create_final_file(argv, argc, envp);
	return (pipe_final_cmd(file));
}

t_file	create_final_file(char **argv, int argc, char **envp)
{
	t_file	file;

	if (!ft_strcmp(argv[1], "here_doc"))
		file = create_file(argv[argc - 1], argv[argc - 2], envp, O_CREAT
				| O_WRONLY | O_APPEND);
	else
		file = create_file(argv[argc - 1], argv[argc - 2], envp, O_CREAT
				| O_WRONLY | O_TRUNC);
	return (file);
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

-	output of this command is incorrect
./pipex file1 poopoostinky wc file2

 */
