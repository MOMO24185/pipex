/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:21:08 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/05 13:13:47 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_pipe(int *pipe_fd, int pid)
{
	char	*str;

	str = get_next_line(pipe_fd[1]);
	if (str)
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
