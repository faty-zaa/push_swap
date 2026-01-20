/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:22:49 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/19 09:42:00 by falamlih         ###   ########.fr       */
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

int	main(int arc, char **arv)
{
	t_ilist	*stack;

	if (arc < 2)
		return (0);
	stack = ft_checker(arc, arv);
	if (!stack)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	write(1, "OK\n", 3);
	free_list(stack);
	return (0);
}
