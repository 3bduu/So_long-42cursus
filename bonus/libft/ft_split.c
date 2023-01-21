/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:08:47 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:19 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static int	memory_case_of_db_ptr(char *s, char c)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			j++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (j);
}

static void	*free_allocation(char **p, int j)
{
	while (j - 1 >= 0)
	{
		free(p[j - 1]);
		j--;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*org_str;
	char	**p;

	i = 0;
	p = malloc((memory_case_of_db_ptr((char *)s, c) + 1) * sizeof(char *));
	if (!s || !p)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			org_str = (char *)s;
			while (*s && *s != c)
				++s;
			p[i] = ft_substr(org_str, 0, (s - org_str));
			if (!p[i])
				return (free_allocation(p, i));
			i++;
		}
		else
			++s;
	}
	p[i] = NULL;
	return (p);
}
