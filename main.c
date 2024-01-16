/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:55:49 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/12 14:51:07 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_file file;
	int		count;

	if (argc < 5)
		exit_failure(POOPOO_USAGE, NULL, file);
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
	execute_cmd(file);
	free_file(file);
}
