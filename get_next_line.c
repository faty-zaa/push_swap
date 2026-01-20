/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:13:43 by falamlih          #+#    #+#             */
/*   Updated: 2025/11/29 09:23:09 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *buff)
{
	size_t	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_from(int fd)
{
	ssize_t	i;
	char	*buff;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	if (i <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	return (buff);
}

char	*line(int fd, char *buff)
{
	char	*swap;
	char	*readbuff;

	if (fd < 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	if (!buff)
		return (NULL);
	readbuff = read_from(fd);
	while (readbuff)
	{
		swap = buff;
		buff = ft_strjoin(swap, readbuff);
		free(readbuff);
		free(swap);
		if (!buff)
			return (NULL);
		if (check_nl(buff))
			break ;
		readbuff = read_from(fd);
	}
	return (buff);
}

char	*next_l(char *buff)
{
	size_t	i;
	char	*tmp;
	size_t	j;

	i = 0;
	if (!buff || !buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = buff[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	char		*last;
	size_t		i;

	buff = line(fd, buff);
	if (!buff)
		return (NULL);
	tmp = next_l(buff);
	if (!tmp)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n' && buff[i + 1] != '\0')
		last = ft_strdup(buff + i + 1);
	else
		last = NULL;
	free(buff);
	buff = last;
	return (tmp);
}
