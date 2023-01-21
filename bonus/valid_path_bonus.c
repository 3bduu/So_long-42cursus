/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:46:34 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 12:06:43 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	valid_extension(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] == 'r' && path[i - 2] == 'e' && path[i - 3] == 'b' && path[i
			- 4] == '.')
		return (1);
	return (0);
}

int	valid_map1(char **map)
{
	int	i;
	int	x;

	i = -1;
	x = -1;
	if (!map[0] || !map[1] || !map[2])
		return (0);
	while (map[++i])
		if ((ft_strlen(map[0]) != ft_strlen(map[i])) || (map[i][0] != '1'
			|| map[i][ft_strlen(map[i]) - 1] != '1'))
			return (0);
	while (map[0][++x])
		if (map[0][x] != '1')
			return (0);
	x = -1;
	while (map[i - 1][++x])
		if (map[i - 1][x] != '1')
			return (0);
	return (1);
}

int	valid_map2(t_my_struct game)
{
	game.i = -1;
	game.n_exit = 0;
	game.n_player = 0;
	game.n_collect = 0;
	while (game.map[++game.i])
	{
		game.j = -1;
		while (game.map[game.i][++game.j])
		{
			if (!check_components(game))
				return (0);
			else if (game.map[game.i][game.j] == 'P')
				game.n_player++;
			else if (game.map[game.i][game.j] == 'C')
				game.n_collect++;
			else if (game.map[game.i][game.j] == 'E')
				game.n_exit++;
		}
	}
	if (game.n_player > 1 || game.n_exit > 1 || !game.n_player || !game.collect
		|| !game.n_exit)
		return (0);
	return (1);
}

void	valid_map3(t_my_struct *game)
{
	game->i = 0;
	game->r = 0;
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->r++;
				break ;
			}
			game->j++;
		}
		if (game->r != 0)
			break ;
		game->i++;
	}
}

void	valid_map4(t_my_struct *game, char *str)
{
	t_my_struct2	game2;

	game2.i = 0;
	game->mapp = our_map2(str, game2);
	floodfill(game, game->i, game->j);
	game->mapp3 = our_map3(str, game2);
	floodfill2(game, game->i, game->j);
	if (!check_collect2(game->mapp) && !check_collect3(game->mapp3))
	{
		free_map(game->mapp);
		free_map(game->mapp3);
		init_project(game);
		mlx_loop(game->mlx);
		ft_printf("You win!!");
	}
	else
	{
		free_map(game->map);
		ft_printf("Error\nInvalid Map");
		exit(0);
	}
}
