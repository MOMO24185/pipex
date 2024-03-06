/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:21:08 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/06 14:21:11 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_pipe(int *pipe_fd, int pid, char *cmd)
{
	char	*str;

	str = get_next_line(pipe_fd[1]);
	if (ft_strnstr(cmd, "sleep", ft_strlen(cmd)))
		waitpid(pid, NULL, 0);
	else if (str)
	{
		str = gnl_till_null(pipe_fd, str);
		ft_putstr_fd(str, pipe_fd[1]);
		ft_putendl_fd(str, STDERR_FILENO);
		free(str);
		waitpid(pid, NULL, 0);
	}
}

char	*gnl_till_null(int *pipe_fd, char *str)
{
	char	*temp;

	temp = get_next_line(pipe_fd[1]);
	while (temp)
	{
		str = join_strs(str, temp);
		free(temp);
		temp = get_next_line(pipe_fd[1]);
	}
	return (str);
}

void	limiter_check(char *limiter)
{
	char	*str;
	char	*temp;
	int		my_pipes[2];
	t_file	file;

	if (pipe(my_pipes) == -1)
		exit_failure(POOPOO_PIPE, free_file, file, 1);
	close(my_pipes[0]);
	dup2(my_pipes[1], 1);
	str = NULL;
	temp = get_next_line(0);
	while (ft_strcmp(limiter, temp))
	{
		str = join_strs(str, temp);
		free(temp);
		temp = get_next_line(0);
	}
	ft_putstr_fd(str, 0);
	free(str);
	free(temp);
}
