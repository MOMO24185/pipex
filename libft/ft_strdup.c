/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:43:14 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/08 12:33:09 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		c;
	char	*str;

	str = malloc(ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	c = -1;
	while (src[++c])
		str[c] = src[c];
	str[c] = 0;
	return (str);
}
