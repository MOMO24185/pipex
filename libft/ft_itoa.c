/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:34:51 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 12:34:11 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_negative(int nbr, char *str);
static int	get_num_len(int nbr);

char	*ft_itoa(int n)
{
	char	*str;
	int		num_len;

	num_len = get_num_len(n);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (check_negative(n, str))
		n *= -1;
	str[num_len] = 0;
	while (num_len--)
	{
		if (str[0] == '-' && num_len == 0)
			break ;
		str[num_len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	get_num_len(int nbr)
{
	int	c;

	c = 0;
	if (nbr <= 0)
		c++;
	while (nbr != 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

static int	check_negative(int nbr, char *str)
{
	if (nbr < 0)
	{
		str[0] = '-';
		return (1);
	}
	return (0);
}
