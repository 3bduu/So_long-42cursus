/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:25:46 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:36 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static int	where_is_new_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*join_with_new_line(char **remainder, char **buff)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	str = ft_strdup(*remainder);
	j = where_is_new_line(str, '\n');
	free(*remainder);
	*remainder = ft_strdup(str + (j + 1));
	str[j + 1] = 0;
	free(*buff);
	return (str);
}

static char	*remainder_func(char **str, char **buff)
{
	char	*rm;

	rm = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(*buff);
	return (rm);
}

static char	*free_func(char **buff, char **remainder)
{
	free(*buff);
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buff;
	ssize_t		rd;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd >= 0)
	{
		buff[rd] = '\0';
		remainder = ft_strjoin(remainder, buff);
		if (where_is_new_line(remainder, '\n') != -1)
			return (join_with_new_line(&remainder, &buff));
		if (!rd && remainder[0] == '\0')
			break ;
		if (!rd)
			return (remainder_func(&remainder, &buff));
		rd = read(fd, buff, BUFFER_SIZE);
	}
	return (free_func(&buff, &remainder));
}
