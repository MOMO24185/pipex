/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:21:08 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/08 09:37:42 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_pipe(int pid, char *cmd)
{
	if (ft_strnstr(cmd, "sleep", ft_strlen(cmd)))
		waitpid(pid, NULL, 0);
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
