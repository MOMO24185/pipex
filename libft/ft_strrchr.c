/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:25:52 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/08 14:08:48 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		count;

	count = ft_strlen((char *)s);
	while (count > 0)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count--;
	}
	if (s[count] == (char)c)
		return ((char *)&s[count]);
	return (NULL);
}
