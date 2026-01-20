/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:40:11 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 16:21:26 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

static void	ft_put_rank(int *arr, t_ilist *tmp, int len)
{
	int	j;

	while (tmp->next)
	{
		j = -1;
		while (++j < len)
		{
			if (arr[j] == tmp->value)
			{
				tmp->rank = j;
				break ;
			}
		}
		tmp = tmp->next;
	}
	j = -1;
	while (++j < len)
	{
		if (arr[j] == tmp->value)
		{
			tmp->rank = j;
			break ;
		}
	}
}

static int	ft_rank(t_ilist **stack)
{
	int		*arr;
	int		len;
	t_ilist	*tmp;
	int		i;

	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	len = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (tmp->next)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	arr[i] = tmp->value;
	ft_sort_arr(arr, len);
	tmp = *stack;
	ft_put_rank(arr, tmp, len);
	return (free(arr), len);
}

static int	get_chunk(int size)
{
	if (size <= 100)
		return (16);
	return (32);
}

int	num(int arc, char **arv, t_ilist **stacka)
{
	int		max;
	t_ilist	*stackb;

	*stacka = ft_list(arc, arv);
	max = ft_lstsize(*stacka);
	stackb = NULL;
	if (is_sorted(*stacka))
	{
		free_list(*stacka);
		exit(0);
	}
	if (max == 2)
		sa(stacka);
	else if (max == 3 || max == 4)
		ft_th_four(stacka, &stackb);
	else if (max == 5)
		ft_five(stacka, &stackb);
	if (max <= 5)
	{
		free_list(*stacka);
		free_list(stackb);
		exit(0);
	}
	max = get_chunk(ft_rank(stacka));
	return (max);
}
