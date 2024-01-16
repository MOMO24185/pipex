/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:59:51 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/03 08:20:42 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	const char	*str_src;
	char		*str_dst;

	if (!dst && !src)
		return (dst);
	str_src = (const char *)src;
	str_dst = (char *)dst;
	count = 0;
	if (n > 0)
	{
		while (count < n)
		{
			str_dst[count] = str_src[count];
			count++;
		}
	}
	return (dst);
}
