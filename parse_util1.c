/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:20:10 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/19 12:29:53 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calw(char const *s, char c)
{
	size_t	i;
	int		cl;
	int		f;

	i = 0;
	cl = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] != c && f == 0)
		{
			f = 1;
			cl++;
		}
		else if (s[i] == c)
			f = 0;
		i++;
	}
	return (cl);
}

static char	**fre(char **wr, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free(wr[i]);
		i++;
	}
	free(wr);
	return (NULL);
}

static char	**word(const char *s, char c, int cl, int l)
{
	size_t	i;
	char	**wr;
	size_t	st;

	wr = (char **)malloc((cl + 1) * sizeof(char *));
	if (!wr)
		return (NULL);
	st = 0;
	while (s[st] && l < cl)
	{
		i = 0;
		while (s[st] == c && s[st])
			st++;
		while (s[st + i] != c && s[st + i])
			i++;
		wr[l] = ft_substr(s, st, i);
		if (!wr[l])
			return (fre(wr, l));
		st += i;
		l++;
	}
	wr[l] = NULL;
	return (wr);
}

char	**ft_split(char const *s, char c)
{
	int	cl;
	int	l;

	if (!s)
		return (NULL);
	cl = calw(s, c);
	l = 0;
	return (word(s, c, cl, l));
}

int	alloc(long *dup, int l, long **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (dup[i] == dup[j])
			{
				write (2, "Error\n", 6);
				return 0;
			}
			j++;
		}
		i++;
	}
	*arr = malloc(i * sizeof(long));
	if (!(*arr))
	{
		free(dup);
		return (0);
	}
	return (i);
}
