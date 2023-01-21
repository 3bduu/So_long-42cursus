/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:47 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:22 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = 0;
	return (p);
}
