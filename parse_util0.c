/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:12:00 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 16:22:16 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	st;
	char	*str;

	if (!s)
		return (NULL);
	st = (size_t)start;
	if (st >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - st)
		len = ft_strlen(s) - st;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + st];
		i++;
	}
	str[i] = '\0';
	return (str);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	s;
	long	nj;
	int		n;

	i = 0;
	s = 1;
	while (i && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	nj = 0;
	n = i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nj = nj * 10 + (nptr[i] - '0');
		i++;
	}
	if (i - n > 12)
		return (2147483649);
	return (nj * s);
}

char	*ft_join(char *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (free(s1), NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

int	ft_lstsize(t_ilist *lst)
{
	int		i;
	t_ilist	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
