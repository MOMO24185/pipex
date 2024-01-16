/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:59:34 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 10:19:53 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				total;
	int				count;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (str);
	count = 0;
	total = 0;
	while (s1[count])
		str[total++] = s1[count++];
	count = 0;
	while (s2[count])
	{
		str[total] = s2[count];
		count++;
		total++;
	}
	str[total] = 0;
	return (str);
}
