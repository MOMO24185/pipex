/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:27:06 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/12 12:48:06 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strchr_gnl(const char *s, int c)
{
	int		count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count])
	{
		if (s[count] == (char)c)
			return (count);
		count++;
	}
	if (s[count] == (char)c)
		return (count);
	return (-1);
}

char	*strjoin_gnl(char const *s1, char const *s2)
{
	size_t			total;
	size_t			count;
	char			*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	count = 0;
	total = 0;
	while (s1 && s1[count])
		str[total++] = s1[count++];
	count = 0;
	while (s2 && s2[count])
		str[total++] = s2[count++];
	str[total] = 0;
	return (str);
}

void	strcpy_gnl(char *dst, const char *src)
{
	size_t	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			dst[i] = src[i];
		dst[i] = 0;
	}
	while (++i <= BUFFER_SIZE)
		dst[i] = 0;
}
