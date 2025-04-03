/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:11:25 by sara              #+#    #+#             */
/*   Updated: 2025/03/17 12:59:35 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fft_lstsize(t_ps *head)
{
    int i;
    t_ps *tmp;

    tmp = head;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

t_ps	*fft_lstnew(int num)
{
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	fft_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*ptr;

	ptr = *lst;
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = fft_lstlast(*lst);
	ptr->next = new;
}

void	fft_lstclear(t_ps **lst)
{
	t_ps	*temp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
}

t_ps	*fft_lstlast(t_ps *lst)
{
	t_ps	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
