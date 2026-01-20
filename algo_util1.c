/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:21:55 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 15:36:45 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_ilist *stackb)
{
	int	i;

	i = 0;
	if (!stackb)
		return (0);
	while (stackb->next)
	{
		if (stackb->rank > i)
			i = stackb->rank;
		stackb = stackb->next;
	}
	if (stackb->rank > i)
		i = stackb->rank;
	return (i);
}

static int	ft_position(t_ilist *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

t_ilist	*ft_stackb(int arc, char **arv, int push)
{
	t_ilist	*stacka;
	t_ilist	*stackb;
	int		max;

	max = num(arc, arv, &stacka);
	stackb = NULL;
	while (stacka)
	{
		if (stacka->rank <= push)
		{
			pb(&stacka, &stackb);
			rb(&stackb);
			push++;
		}
		else if (stacka->rank < push + max)
		{
			pb(&stacka, &stackb);
			push++;
		}
		else
			ra(&stacka);
	}
	return (stackb);
}

t_ilist	*ft_sort(int arc, char **arv)
{
	t_ilist	*stacka;
	t_ilist	*stackb;
	int		max;
	int		pos;

	if (arc < 2)
		return (NULL);
	stacka = NULL;
	stackb = ft_stackb(arc, arv, 0);
	if (!stackb)
		return (NULL);
	while (stackb)
	{
		max = ft_max(stackb);
		while (stackb->rank != max)
		{
			pos = ft_position(stackb, max);
			if (pos <= ft_lstsize(stackb) / 2)
				rb(&stackb);
			else
				rrb(&stackb);
		}
		pa(&stacka, &stackb);
	}
	return (stacka);
}

int	main(int arc, char **arv)
{
	t_ilist	*stack;

	stack = NULL;
	stack = ft_sort(arc, arv);
	if (!stack)
		return (0);
	free_list(stack);
}
