/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/14 10:01:22 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipe_final_cmd(t_file file);

int	main(int argc, char **argv, char **envp)
{
	int		p[2];
	int		i;
	t_file	file;

	file = create_file(NULL, NULL, NULL, 0);
	if (argc != 5)
		return (ft_putendl_fd(POOPOO_USAGE, STDERR_FILENO), 0);
	if (pipe(p) == -1)
		exit_failure(POOPOO_PIPE, free_file, file, 1);
	i = 1;
	while (++i < argc - 2)
	{
		while (!argv[i])
			i++;
		if (i == 2)
			pipe_cmd(create_file(argv[1], argv[i], envp, O_RDONLY), 1, p);
		else
			pipe_cmd(create_file(argv[1], argv[i], envp, O_RDONLY), 0, p);
	}
	return (close(p[0]), pipe_final_cmd(create_file(argv[argc - 1],
				argv[argc - 2], envp, O_CREAT | O_WRONLY | O_TRUNC)));
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
	return (free_file(file), status);
}
