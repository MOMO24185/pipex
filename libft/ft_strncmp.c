/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:08:47 by melshafi          #+#    #+#             */
/*   Updated: 2024/03/11 14:29:08 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				count;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (!s1 || !s2)
		return (-1);
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (!ptr1[count] || (ptr1[count] != ptr2[count]))
			return (ptr1[count] - ptr2[count]);
		count++;
	}
	return (0);
}
