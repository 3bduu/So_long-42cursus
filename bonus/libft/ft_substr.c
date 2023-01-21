/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:13:00 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:33 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (start + len >= ft_strlen(s))
		p = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		p = malloc((len * sizeof(char)) + 1);
	if (!p)
		return (NULL);
	while (s[start] && i < len)
		p[i++] = s[start++];
	p[i++] = '\0';
	return (p);
}
