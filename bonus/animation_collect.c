/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_collect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:19:27 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:46 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animation_collect(t_my_struct *game)
{
	if (game->loop < 900)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	if (game->c_position == 1)
		return_mlx_xpm1(game, "textures/collect.xpm");
	if (game->c_position == 2)
		return_mlx_xpm1(game, "textures/collect2.xpm");
	if (game->c_position == 3)
		return_mlx_xpm1(game, "textures/collect4.xpm");
	if (game->c_position == 4)
		return_mlx_xpm1(game, "textures/collect5.xpm");
	if (game->c_position == 5)
	{
		return_mlx_xpm1(game, "textures/collect6.xpm");
		game->c_position = 0;
	}
	enemy_hooks(game);
	my_map(game);
	game->c_position++;
	return (0);
}

void	animation_player(t_my_struct *game)
{
	while (game->loop < 9000)
		game->loop++;
	game->loop = 0;
	if (game->p_position == 1)
		animation_player_lr(game, "textures/gogo1.xpm");
	else if (game->p_position == 3)
		animation_player_lr(game, "textures/gogo3.xpm");
	else if (game->p_position == 4)
		animation_player_lr(game, "textures/gogo4.xpm");
	else if (game->p_position == 5)
		animation_player_lr(game, "textures/gogo5.xpm");
	else if (game->p_position == 6)
		animation_player_lr(game, "textures/gogo6.xpm");
	else if (game->p_position == 7)
		animation_player_lr(game, "textures/gogo7.xpm");
	else if (game->p_position == 9)
		animation_player_lr(game, "textures/gogo16.xpm");
	else if (game->p_position == 10)
		animation_player_lr(game, "textures/gogo17.xpm");
	else if (game->p_position > 10)
		animation_super_player_lr(game);
	game->p_position++;
}

void	enemy_hooks(t_my_struct *game)
{
	if (game->e_position == 1)
		return_mlx_xpm2(game, "textures/1.xpm");
	else if (game->e_position == 2)
		return_mlx_xpm2(game, "textures/2.xpm");
	else if (game->e_position == 3)
		return_mlx_xpm2(game, "textures/3.xpm");
	else if (game->e_position == 4)
		return_mlx_xpm2(game, "textures/3.xpm");
	else if (game->e_position == 5)
		return_mlx_xpm2(game, "textures/5.xpm");
	else if (game->e_position == 6)
		return_mlx_xpm2(game, "textures/6.xpm");
	else if (game->e_position == 8)
		return_mlx_xpm2(game, "textures/8.xpm");
	else if (game->e_position == 9)
		return_mlx_xpm2(game, "textures/9.xpm");
	else if (game->e_position == 10)
	{
		return_mlx_xpm2(game, "textures/10.xpm");
		game->e_position = 0;
	}
	game->e_position++;
}

void	animation_player_lr(t_my_struct *game, char *str)
{
	game->player_right = mlx_xpm_file_to_image(game->mlx, str, &game->img_w,
			&game->img_h);
	game->player_left = mlx_xpm_file_to_image(game->mlx, str, &game->img_w,
			&game->img_h);
}

void	animation_super_player_lr(t_my_struct *game)
{
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/super_right.xpm", &game->img_w, &game->img_h);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/super_left.xpm", &game->img_w, &game->img_h);
}
