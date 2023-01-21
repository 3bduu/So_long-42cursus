/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:20:46 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:50 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_collect(t_my_struct *map_game)
{
	int	i;
	int	j;

	i = 0;
	map_game->n_collect = 0;
	while (map_game->map[i])
	{
		j = 0;
		while (map_game->map[i][j])
		{
			if (map_game->map[i][j] == 'C')
				map_game->n_collect++;
			j++;
		}
		i++;
	}
	return (map_game->n_collect);
}

int	check_collect2(char **mapp)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	t = 0;
	while (mapp[i])
	{
		j = 0;
		while (mapp[i][j])
		{
			if (mapp[i][j] == 'C')
				t++;
			j++;
		}
		i++;
	}
	return (t);
}

int	check_collect3(char **mapp)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	t = 0;
	while (mapp[i])
	{
		j = 0;
		while (mapp[i][j])
		{
			if (mapp[i][j] == 'E')
				t++;
			j++;
		}
		i++;
	}
	return (t);
}

void	floodfill(t_my_struct *game, int x, int y)
{
	if (game->mapp[x][y] == 'P' || game->mapp[x][y] == '0'
		|| game->mapp[x][y] == 'C')
	{
		game->mapp[x][y] = 'X';
		floodfill(game, x + 1, y);
		floodfill(game, x, y + 1);
		floodfill(game, x - 1, y);
		floodfill(game, x, y - 1);
	}
}

void	floodfill2(t_my_struct *game, int x, int y)
{
	if (game->mapp3[x][y] == 'P' || game->mapp3[x][y] == '0'
		|| game->mapp3[x][y] == 'E' || game->mapp3[x][y] == 'C')
	{
		game->mapp3[x][y] = 'X';
		floodfill2(game, x + 1, y);
		floodfill2(game, x, y + 1);
		floodfill2(game, x - 1, y);
		floodfill2(game, x, y - 1);
	}
}
