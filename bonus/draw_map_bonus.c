/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:29:02 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:52 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	p_game(t_my_struct *map_game, int i, int j)
{
	map_game->player_y = i;
	map_game->player_x = j;
	if (map_game->right == 1)
		mlx_put_image_to_window(map_game->mlx, map_game->win,
			map_game->player_right, j * 60, i * 60);
	else
		mlx_put_image_to_window(map_game->mlx, map_game->win,
			map_game->player_left, j * 60, i * 60);
}

void	e_game(t_my_struct *map_game, int i, int j)
{
	if (check_collect(map_game))
		mlx_put_image_to_window(map_game->mlx, map_game->win,
			map_game->close_dor, j * 60, i * 60);
	else
		mlx_put_image_to_window(map_game->mlx, map_game->win,
			map_game->open_dor, j * 60, i * 60);
}

void	n_game(t_my_struct *map_game)
{
	mlx_put_image_to_window(map_game->mlx, map_game->win, map_game->enemy,
		map_game->j * 60, map_game->i * 60);
}

void	c_game(t_my_struct *map_game)
{
	mlx_put_image_to_window(map_game->mlx, map_game->win, map_game->collect,
		map_game->j * 60, map_game->i * 60);
}

void	player_animation_case(t_my_struct *map_game)
{
	if (map_game->n_collect)
	{
		map_game->player_left = mlx_xpm_file_to_image(map_game->mlx,
				"textures/player_left.xpm", &map_game->img_w,
				&map_game->img_h);
		map_game->player_right = mlx_xpm_file_to_image(map_game->mlx,
				"textures/player_right.xpm", &map_game->img_w,
				&map_game->img_h);
	}
	else if (!map_game->n_collect)
		animation_player(map_game);
}
