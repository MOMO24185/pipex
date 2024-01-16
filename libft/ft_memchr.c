/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:36:34 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/13 08:21:23 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	size_t			count;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		if ((unsigned char)str[count] == (unsigned char)c)
			return ((unsigned char *)&str[count]);
		count++;
	}
	return (NULL);
}
