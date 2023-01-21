/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:31:41 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:59:37 by abenlahb         ###   ########.fr       */
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
