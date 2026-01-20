/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:28:32 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/19 09:44:19 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ilist **list)
{
	t_ilist	*first;
	t_ilist	*second;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = (*list);
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	(*list) = second;
}

void	ss(t_ilist **alist, t_ilist **blist)
{
	swap(alist);
	swap(blist);
}

void	pac(t_ilist **alist, t_ilist **blist)
{
	t_ilist	*tmpb;
	t_ilist	*tmpa;

	if ((*blist) == NULL)
		return ;
	tmpb = (*blist);
	(*blist) = (*blist)->next;
	tmpa = (*alist);
	(*alist) = tmpb;
	(*alist)->next = tmpa;
}

t_ilist	*is_sorted(t_ilist *stacka)
{
	t_ilist	*tmp;

	tmp = stacka;
	while (stacka && stacka->next)
	{
		if (stacka->next->value < stacka->value)
			return (NULL);
		stacka = stacka->next;
	}
	return (tmp);
}

void	rrr(t_ilist **lista, t_ilist **listb)
{
	reverse(lista);
	reverse(listb);
}
