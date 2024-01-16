/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:22:46 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/13 09:07:19 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_one;
	t_list	*next_one;

	if (!*lst || !del)
		return ;
	del_one = *lst;
	while (del_one)
	{
		next_one = del_one->next;
		ft_lstdelone(del_one, del);
		del_one = next_one;
	}
	*lst = NULL;
}
