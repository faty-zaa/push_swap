/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:43:15 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/16 16:20:58 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ilist **list)
{
	rotate(list);
	write(1, "ra\n", 3);
}

void	rb(t_ilist **list)
{
	rotate(list);
	write(1, "rb\n", 3);
}

void	pb(t_ilist **alist, t_ilist **blist)
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
	write(1, "pb\n", 3);
}

void	pa(t_ilist **alist, t_ilist **blist)
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
	write(1, "pa\n", 3);
}

void	rrb(t_ilist **list)
{
	reverse(list);
	write(1, "rrb\n", 4);
}
