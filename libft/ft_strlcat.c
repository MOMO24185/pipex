/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:07:36 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/08 17:10:51 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	result_count;
	size_t	total_size;
	size_t	true_size;

	if (!dest && !size)
		return (0);
	result_count = ft_strlen(dest);
	true_size = result_count;
	if (size <= result_count)
		return (size + ft_strlen(src));
	total_size = (result_count) + (ft_strlen(src));
	count = 0;
	if (size > 0)
	{
		while (src[count] != 0 && true_size < (size - 1))
		{
			dest[true_size] = src[count];
			count++;
			true_size++;
		}
		dest[true_size] = 0;
	}
	return (total_size);
}
