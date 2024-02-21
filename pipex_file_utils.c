/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:05:50 by melshafi          #+#    #+#             */
/*   Updated: 2024/02/21 17:22:06 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_file	create_file(char *name, char *args, char **envp, int mode)
{
	t_file	file;

	file.name = name;
	file.fd = -1;
	if (name)
	{
		if (mode == 0)
			file.fd = open(name, O_RDONLY, 0777);
		else if (mode == 1)
			file.fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (file.fd == -1)
			exit_failure(file.name, NULL, file, 1);
		file.args = ft_split(args, ' ');
		if (!ft_strncmp(file.args[0], "./", 2))
			file.path = get_path(envp, file.args[0], "PWD");
		else
			file.path = get_path(envp, file.args[0], "PATH");
		if (!ft_strcmp(file.args[0], "./pipex") || !ft_strcmp(file.args[0],
				"pipex"))
			exit_failure(POOPOO_USAGE, free_file, file, 0);
		printf("PATH(%s)\n", file.path);
		file.envp = envp;
	}
	return (file);
}

char	*get_all_paths(char **envp, char *var)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		path = ft_substr(envp[i], 0, j);
		if (ft_strcmp(path, var) == 0)
		{
			free(path);
			return (&envp[i][j + 1]);
		}
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd, char *var)
{
	char	**paths_split;
	char	*path;
	int		i;

	i = -1;
	paths_split = ft_split(get_all_paths(envp, var), ':');
	if (!paths_split)
		return (NULL);
	while (paths_split[++i])
	{
		path = join_strs(ft_strjoin(paths_split[i], "/"), cmd);
		if (!access(path, F_OK | X_OK))
		{
			free_2dchar(paths_split);
			return (path);
		}
		free(path);
	}
	free_2dchar(paths_split);
	return (NULL);
}

char	*join_strs(char *str, char *buffer)
{
	char	*temp;

	temp = str;
	str = ft_strjoin(temp, buffer);
	return (free(temp), str);
}

void	free_2dchar(char **str)
{
	size_t	c;

	c = 0;
	while (str[c])
		free(str[c++]);
	free(str);
}
