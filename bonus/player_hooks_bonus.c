/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:31:41 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 12:27:37 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_move(t_my_struct *player, char c)
{
	player->left = 0;
	player->right = 0;
	if (c == 'w')
		w_player(player);
	else if (c == 's')
		s_player(player);
	else if (c == 'a')
		a_player(player);
	else if (c == 'd')
		d_player(player);
	ft_printf("Move : %d\n", player->move);
	mlx_clear_window(player->mlx, player->win);
	my_map(player);
}

int	player_hooks(int key, t_my_struct *player)
{
	if (key == W)
	{
		player->player_y--;
		player_move(player, 'w');
	}
	else if (key == A)
	{
		player->player_x--;
		player_move(player, 'a');
	}
	else if (key == S)
	{
		player->player_y++;
		player_move(player, 's');
	}
	else if (key == D)
	{
		player->player_x++;
		player_move(player, 'd');
	}
	else if (key == ESC)
		end_of_game(player);
	return (0);
}

int	check_components(t_my_struct game)
{
	if (game.map[game.i][game.j] != '0' && game.map[game.i][game.j] != '1'
		&& game.map[game.i][game.j] != 'C' && game.map[game.i][game.j] != 'E'
		&& game.map[game.i][game.j] != 'P' && game.map[game.i][game.j] != 'N')
		return (0);
	return (1);
}

void	put_string(t_my_struct *map_game)
{
	char	*p;
	char	*t;

	p = ft_itoa(map_game->move);
	t = ft_strjoin(ft_strdup("Move : "), p);
	mlx_string_put(map_game->mlx, map_game->win, 10, 10, 0, t);
	free(p);
	free(t);
}
