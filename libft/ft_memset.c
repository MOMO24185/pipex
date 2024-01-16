/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:11:41 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/08 12:11:20 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	char_c;
	unsigned char	*str;
	size_t			count;

	char_c = (unsigned char)c;
	str = (unsigned char *)b;
	count = 0;
	while (count < len)
		str[count++] = char_c;
	return (b);
}
