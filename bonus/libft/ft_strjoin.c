/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:05:23 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:24 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	x;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!p)
		return (NULL);
	while (s1[x])
	{
		p[x] = s1[x];
		x++;
	}
	x = 0;
	while (s2[x])
	{
		p[ft_strlen((char *)s1) + x] = s2[x];
		x++;
	}
	p[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = 0;
	free((void *)s1);
	s1 = NULL;
	return (p);
}
