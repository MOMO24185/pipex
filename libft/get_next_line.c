/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:27:07 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/10 12:59:22 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*final_iter(char *str, char *buffer, int size);
static char	*end_of_file(char *str, char *buffer, int size);
static char	*join_strs(char *str, char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[(ssize_t)BUFFER_SIZE + 1];
	char		*str;
	int			size;
	ssize_t		read_bytes;

	size = -1;
	str = strjoin_gnl(NULL, buffer);
	while (size == -1 && strchr_gnl(str, '\n') < 0)
	{
		read_bytes = read(fd, buffer, (ssize_t)BUFFER_SIZE);
		if (read_bytes > 0)
			buffer[read_bytes] = 0;
		if (read_bytes < (ssize_t)BUFFER_SIZE && strchr_gnl(buffer, '\n') < 0)
		{
			if (read_bytes != -1 && buffer[0])
				return (end_of_file(str, buffer, read_bytes));
			strcpy_gnl(buffer, NULL);
			return (free(str), NULL);
		}
		size = strchr_gnl(buffer, '\n');
		if (size >= 0)
			return (final_iter(str, buffer, size));
		str = join_strs(str, buffer);
	}
	return (free(str), final_iter(NULL, buffer, strchr_gnl(buffer, '\n')));
}

static char	*join_strs(char *str, char *buffer)
{
	char	*temp;

	temp = str;
	str = strjoin_gnl(temp, buffer);
	return (free(temp), str);
}

static char	*final_iter(char *str, char *buffer, int size)
{
	char	temp;

	temp = buffer[size + 1];
	buffer[size + 1] = 0;
	str = join_strs(str, buffer);
	buffer[size + 1] = temp;
	strcpy_gnl(buffer, &buffer[size + 1]);
	return (str);
}

static char	*end_of_file(char *str, char *buffer, int size)
{
	buffer[size] = 0;
	str = join_strs(str, buffer);
	buffer[0] = 0;
	return (str);
}
