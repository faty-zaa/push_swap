/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:55:24 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 16:22:27 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pbc(t_ilist **alist, t_ilist **blist)
{
	t_ilist	*tmpb;
	t_ilist	*tmpa;

	if ((*alist) == NULL)
		return ;
	tmpa = (*alist);
	(*alist) = (*alist)->next;
	tmpb = (*blist);
	(*blist) = tmpa;
	(*blist)->next = tmpb;
}

void	rotate(t_ilist **list)
{
	t_ilist	*tmp;
	t_ilist	*head;

	tmp = (*list);
	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	(*list) = (*list)->next;
	head = (*list);
	while ((*list)->next)
		(*list) = (*list)->next;
	(*list)->next = tmp;
	tmp->next = NULL;
	(*list) = head;
}

void	rr(t_ilist **lista, t_ilist **listb)
{
	rotate(lista);
	rotate(listb);
}

void	reverse(t_ilist **list)
{
	t_ilist	*tmp;
	t_ilist	*head;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	head = (*list);
	tmp = NULL;
	while ((*list)->next)
	{
		tmp = (*list);
		(*list) = (*list)->next;
	}
	tmp->next = NULL;
	(*list)->next = head;
}

void	rra(t_ilist **list)
{
	reverse(list);
	write(1, "rra\n", 4);
}
