/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 18:56:17 by fmolenbe      #+#    #+#                 */
/*   Updated: 2024/05/02 21:15:02 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		(*del)(temp->content);
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
	lst = NULL;
}
