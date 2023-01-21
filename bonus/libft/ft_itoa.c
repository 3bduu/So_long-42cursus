/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:25:20 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:57:55 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static size_t	bytes(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	p;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		p = str[i];
		str[i] = str[j];
		str[j] = p;
		i++;
		j--;
	}
	return (str);
}

static char	*str_content(long b, char *p, size_t j)
{
	size_t	i;

	i = 0;
	if (b < 0)
	{
		b *= -1;
		p[j - 1] = '-';
	}
	if (b == 0)
		p[i] = '0';
	while (b > 0)
	{
		p[i++] = (b % 10) + '0';
		b /= 10;
	}
	p[j] = '\0';
	ft_strrev(p);
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	b;
	size_t	j;

	b = n;
	j = bytes(b);
	p = malloc((j * sizeof(char)) + 1);
	if (!p)
		return (NULL);
	p = str_content(b, p, j);
	return (p);
}
