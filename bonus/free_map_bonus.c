/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:30:28 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:54 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	end_of_game(t_my_struct *so_long)
{
	free_map(so_long->map);
	mlx_destroy_image(so_long->mlx, so_long->close_dor);
	mlx_destroy_image(so_long->mlx, so_long->collect);
	mlx_destroy_image(so_long->mlx, so_long->empty);
	mlx_destroy_image(so_long->mlx, so_long->open_dor);
	mlx_destroy_image(so_long->mlx, so_long->player_left);
	mlx_destroy_image(so_long->mlx, so_long->player_right);
	mlx_destroy_image(so_long->mlx, so_long->wall);
	mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->mlx);
	exit(0);
	return (0);
}

int	img_error(t_my_struct *so_long)
{
	free_map(so_long->map);
	free(so_long->mlx);
	ft_printf("Error\nInvalid img");
	exit(0);
	return (0);
}

void	return_mlx_xpm1(t_my_struct *game, char *str)
{
	game->collect = mlx_xpm_file_to_image(game->mlx,
			str, &game->img_w, &game->img_h);
}

void	return_mlx_xpm2(t_my_struct *game, char *str)
{
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			str, &game->img_w, &game->img_h);
}
