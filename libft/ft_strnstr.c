/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:27:39 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/08 17:07:47 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	find_len;

	find_len = ft_strlen(to_find);
	if (!str && !len)
		return (NULL);
	if (!find_len)
		return ((char *)str);
	while (*str && (len >= find_len))
	{
		if (*str == to_find[0] && !ft_strncmp(str, to_find, find_len))
			return ((char *)str);
		len--;
		str++;
	}
	return (NULL);
}
