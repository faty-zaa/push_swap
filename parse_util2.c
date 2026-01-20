/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:30:57 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 15:04:30 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_input(const char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	if (str[i] == '\0' || !str)
		return (0);
	n = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			j = i + 1;
			if (!ft_isdigit(str[j]) || (i != 0 && str[i - 1] != ' '))
				return (0);
		}
		else if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		else if (str[i] == ' ')
			n++;
		i++;
	}
	if (i == n)
		return (0);
	return (1);
}

void	free_split(char **st)
{
	int	i;

	i = 0;
	if (!st)
		return ;
	while (st[i])
	{
		free(st[i]);
		i++;
	}
	free(st);
}

int	ft_parse(const char *str, long **arr)
{
	int		i;
	char	**st;
	long	val;

	if (ft_input(str) == 0)
		return (0);
	st = ft_split(str, 32);
	if (!st)
		return (0);
	*arr = malloc(count(st) * sizeof(long));
	if (!(*arr))
		return (free_split(st), 0);
	i = 0;
	while (st[i])
	{
		val = ft_atoi(st[i]);
		if (val > 2147483647 || val < -2147483648)
			return (free_split(st), free(*arr), 0);
		(*arr)[i] = val;
		i++;
	}
	return (free_split(st), i);
}

int	ft_arv(char **arv)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	while (arv[i])
	{
		j = 0;
		while (arv[i][j])
		{
			n++;
			j++;
		}
		i++;
	}
	return (n);
}
