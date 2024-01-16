/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:18:26 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 11:16:51 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exists_in(const char *str, char ch);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed_str;
	int			start;
	int			end;
	int			count;

	count = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && exists_in(set, s1[start]))
		start++;
	while (start < end && exists_in(set, s1[end]))
		end--;
	if (start < end)
		trimmed_str = malloc((end - start + 2));
	else
		trimmed_str = malloc(1);
	if (!trimmed_str)
		return (NULL);
	while (start <= end)
		trimmed_str[count++] = s1[start++];
	trimmed_str[count] = 0;
	return (trimmed_str);
}

static int	exists_in(const char *str, char ch)
{
	int	c;

	c = -1;
	while (str[++c])
		if (str[c] == ch)
			return (1);
	return (0);
}
