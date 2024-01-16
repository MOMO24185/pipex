/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:13:41 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 09:57:33 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			count;

	str_dst = (unsigned char *) dest;
	str_src = (unsigned char *) src;
	count = -1;
	if (dest - src < (int)n && dest > src)
	{
		while (--n > 0)
		{
			str_dst[n] = str_src[n];
		}
		str_dst[n] = str_src[n];
	}
	else if (src - dest < (int)n && src > dest)
		while (++count < n)
			str_dst[count] = str_src[count];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
