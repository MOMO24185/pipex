/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:59:59 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/13 09:24:19 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	char			*str;
	size_t			s_len;

	count = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len + start > s_len && start < s_len)
		s_len = s_len - start;
	else if (len <= s_len && start < s_len)
		s_len = len;
	else if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	str = ft_calloc((s_len) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[start] && count < s_len)
		str[count++] = s[start++];
	str[count] = 0;
	return (str);
}
