/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:57:37 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:57 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**our_map(char *file, t_my_struct2 game)
{
	game.ptr2 = ft_strdup("");
	game.fd = open(file, O_RDONLY);
	if (game.fd < 0)
		return (NULL);
	while (1)
	{
		game.ptr1 = get_next_line(game.fd);
		if (ft_strlen(game.ptr1) == 1)
			return (NULL);
		if (game.ptr1 == NULL)
			break ;
		game.ptr3 = game.ptr2;
		game.ptr2 = ft_strjoin(game.ptr3, game.ptr1);
		free(game.ptr1);
	}
	game.map = ft_split(game.ptr2, '\n');
	free(game.ptr2);
	close(game.fd);
	return (game.map);
}

char	**our_map2(char *file, t_my_struct2 game)
{
	game.ptr2 = ft_strdup("");
	game.fd = open(file, O_RDONLY);
	if (game.fd < 0)
		return (NULL);
	while (1)
	{
		game.ptr1 = get_next_line(game.fd);
		if (ft_strlen(game.ptr1) == 1)
			return (NULL);
		if (game.ptr1 == NULL)
			break ;
		game.ptr3 = game.ptr2;
		game.ptr2 = ft_strjoin(game.ptr3, game.ptr1);
		free(game.ptr1);
	}
	game.map = ft_split(game.ptr2, '\n');
	free(game.ptr2);
	close(game.fd);
	return (game.map);
}

char	**our_map3(char *file, t_my_struct2 game)
{
	game.ptr2 = ft_strdup("");
	game.fd = open(file, O_RDONLY);
	if (game.fd < 0)
		return (NULL);
	while (1)
	{
		game.ptr1 = get_next_line(game.fd);
		if (ft_strlen(game.ptr1) == 1)
			return (NULL);
		if (game.ptr1 == NULL)
			break ;
		game.ptr3 = game.ptr2;
		game.ptr2 = ft_strjoin(game.ptr3, game.ptr1);
		free(game.ptr1);
	}
	game.map = ft_split(game.ptr2, '\n');
	free(game.ptr2);
	close(game.fd);
	return (game.map);
}
