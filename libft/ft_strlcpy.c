/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:07:34 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 10:44:48 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	int	i;
	int	src_len;

	if (!sz)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	if ((size_t)src_len > --sz)
		src_len = sz;
	i = -1;
	while (++i < src_len)
		dst[i] = src[i];
	dst[i] = 0;
	return (ft_strlen(src));
}
