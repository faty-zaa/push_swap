/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:34:42 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/19 12:34:40 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	array(const char *str, long **arr)
{
	int		i;
	long	*dup;
	int		len;

	i = 0;
	len = ft_parse(str, &dup);
	if (len == 0 || !dup)
		return (0);
	if (!alloc(dup, len, arr))
	{
		free(dup);
		if(*arr)
			free(*arr);
		return 0;
	}
		while (i < len)
	{
		(*arr)[i] = dup[i];
		i++;
	}
	return (free(dup), len);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return ;
}

static t_ilist	*lst_new(long data)
{
	t_ilist	*new;

	new = malloc(sizeof(t_ilist));
	if (!new)
		return (NULL);
	new->value = data;
	new->next = NULL;
	new->rank = 0;
	return (new);
}

static t_ilist	*stack(const char *str)
{
	long	*arr;
	int		i;
	int		j;
	t_ilist	*head;
	t_ilist	*tmp;

	arr = NULL;
	i = array(str, &arr);
	tmp = malloc(sizeof(t_ilist));
	if (i == 0)
		return (free(tmp), free(arr), NULL);
	j = 1;
	tmp->value = arr[0];
	head = tmp;
	while (j < i)
	{
		tmp->next = lst_new(arr[j]);
		if (!(tmp->next))
			return (free(arr), head);
		tmp = tmp->next;
		j++;
	}
	tmp->next = NULL;
	return (free(arr), head);
}

t_ilist	*ft_list(int arc, char **arv)
{
	int		i;
	char	*str;
	t_ilist	*arr;

	if (arc < 2)
		return (ft_error(), NULL);
	i = ft_arv(arv);
	str = ft_strdup("");
	if (!str)
		return (ft_error(), NULL);
	i = 1;
	while (arv[i])
	{
		str = ft_join(str, arv[i]);
		if (arv[i + 1])
			str = ft_join(str, " ");
		if (!str)
			return (ft_error(), NULL);
		i++;
	}
	arr = stack(str);
	if (!arr)
		return (free(str), ft_error(), NULL);
	return (free(str), arr);
}
