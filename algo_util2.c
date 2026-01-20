/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:13:03 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 16:23:05 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_ilist *stack)
{
	t_ilist	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}

void	sa(t_ilist **stacka)
{
	swap(stacka);
	write(1, "sa\n", 3);
}

static int	get_min(t_ilist *s)
{
	int	min;

	min = s->value;
	while (s)
	{
		if (s->value < min)
			min = s->value;
		s = s->next;
	}
	return (min);
}

void	ft_th_four(t_ilist **stack, t_ilist **stackb)
{
	if (ft_lstsize(*stack) == 3)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
			rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (ft_lstsize(*stack) == 4)
	{
		while ((*stack)->value != get_min(*stack))
			ra(stack);
		pb(stack, stackb);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
			rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		pa(stack, stackb);
	}
}

void	ft_five(t_ilist **stack, t_ilist **stackb)
{
	int	min;

	if (ft_lstsize(*stack) == 5)
	{
		min = get_min(*stack);
		while ((*stack)->value != min)
			ra(stack);
		pb(stack, stackb);
		min = get_min(*stack);
		while ((*stack)->value != min)
			ra(stack);
		pb(stack, stackb);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
			rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		pa(stack, stackb);
		pa(stack, stackb);
	}
}
