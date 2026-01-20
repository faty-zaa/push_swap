/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:23:02 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/19 12:42:01 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_check_line(char *line)
{
	int		i;
	char	*r[11];

	r[0] = "sa\n";
	r[1] = "sb\n";
	r[2] = "ss\n";
	r[3] = "pa\n";
	r[4] = "pb\n";
	r[5] = "ra\n";
	r[6] = "rb\n";
	r[7] = "rr\n";
	r[8] = "rra\n";
	r[9] = "rrb\n";
	r[10] = "rrr\n";
	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, r[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_rules(char *rule, t_ilist **stacka, t_ilist **stackb)
{
	if (!ft_strcmp(rule, "sa\n"))
		swap(stacka);
	else if (!ft_strcmp(rule, "sb\n"))
		swap(stackb);
	else if (!ft_strcmp(rule, "ss\n"))
		ss(stacka, stackb);
	else if (!ft_strcmp(rule, "pa\n"))
		pac(stacka, stackb);
	else if (!ft_strcmp(rule, "pb\n"))
		pbc(stacka, stackb);
	else if (!ft_strcmp(rule, "ra\n"))
		rotate(stacka);
	else if (!ft_strcmp(rule, "rb\n"))
		rotate(stackb);
	else if (!ft_strcmp(rule, "rr\n"))
		rr(stacka, stackb);
	else if (!ft_strcmp(rule, "rra\n"))
		reverse(stacka);
	else if (!ft_strcmp(rule, "rrb\n"))
		reverse(stackb);
	else if (!ft_strcmp(rule, "rrr\n"))
		rrr(stacka, stackb);
	else
		return (0);
	return (1);
}

t_ilist	*ft_check_rules(int arc, char **arv)
{
	t_ilist	*stacka;
	t_ilist	*stackb;
	char	*line;

	stackb = NULL;
	stacka = ft_list(arc, arv);
	if (!stacka)
		return (NULL);
	line = get_next_line(0);
	if (!line)
		return (free_list(stacka), NULL);
	while (line)
	{
		if (!ft_check_line(line))
			return (free_list(stacka), free_list(stackb), free(line),
				ft_error(), NULL);
		if (ft_rules(line, &stacka, &stackb) == 0)
			return (free_list(stacka), free_list(stackb), free(line),
				ft_error(), NULL);
		free(line);
		line = get_next_line(0);
	}
	if (stackb)
		return (free_list(stacka), free_list(stackb), free(line), NULL);
	return (free(line), free_list(stackb), stacka);
}

t_ilist	*ft_checker(int arc, char **arv)
{
	t_ilist	*stacka;

	if (arc < 2)
		return (NULL);
	stacka = ft_check_rules(arc, arv);
	if (!stacka)
		return (NULL);
	if (!is_sorted(stacka))
	{
		free_list(stacka);
		return (NULL);
	}
	return (stacka);
}
