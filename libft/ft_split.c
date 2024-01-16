/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:29:54 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/15 15:39:04 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		split_2(char **strs, const char *str, char sep,
					size_t *true_alloc);
static char		*ft_strndup(const char *str, size_t len, size_t *true_alloc);
static char		**ft_free_2d_array(char **strs, size_t true_alloc);
static size_t	ft_wordcount(const char *str, char sep);

char	**ft_split(const char *str, char sep)
{
	char	**strs;
	int		c;
	size_t	wordcount;
	size_t	true_alloc;

	if (!str)
		return (NULL);
	c = -1;
	true_alloc = 0;
	while (str[++c])
		if (sep != str[c])
			break ;
	wordcount = ft_wordcount(&str[c], sep);
	strs = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	else
		split_2(strs, &str[c], sep, &true_alloc);
	if (true_alloc != wordcount)
		strs = ft_free_2d_array(strs, wordcount);
	else
		strs[true_alloc] = 0;
	return (strs);
}

static void	split_2(char **strs, const char *str, char sep, size_t *true_alloc)
{
	size_t		len;
	size_t		flag_set;

	flag_set = 0;
	len = 0;
	while (*str)
	{
		if (((sep == *str) && flag_set) || (!*(str + 1)))
		{
			if (!*(str + 1) && (sep != *str))
				*strs = ft_strndup((str - len), len + 1, true_alloc);
			else if (sep == *str && flag_set)
				*strs = ft_strndup((str - len), len, true_alloc);
			strs++;
			len = 0;
			flag_set = 0;
		}
		else if (sep != *str)
		{
			if (!flag_set)
				flag_set = 1;
			len++;
		}
		(str)++;
	}
}

static char	*ft_strndup(const char *str, size_t len, size_t *true_alloc)
{
	char	*dup;
	size_t	c;

	c = 0;
	dup = (char *)malloc(((len) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	if (str[0] == 0)
		dup[0] = 0;
	while (c < len)
	{
		dup[c] = str[c];
		c++;
	}
	dup[c] = 0;
	(*true_alloc)++;
	return (dup);
}

static char	**ft_free_2d_array(char **strs, size_t words)
{
	size_t	c;

	c = 0;
	while (c < words)
	{
		free(strs[c]);
		c++;
	}
	free(strs);
	return (NULL);
}

static size_t	ft_wordcount(const char *str, char sep)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str == sep)
			flag = 0;
		else if (*str != sep && !flag)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}
