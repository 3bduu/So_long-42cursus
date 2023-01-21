/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:05:03 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 12:33:26 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_img(t_my_struct *map_game)
{
	map_game->close_dor = mlx_xpm_file_to_image(map_game->mlx,
			"textures/close_dor.xpm", &map_game->img_w, &map_game->img_h);
	animation_collect(map_game);
	map_game->empty = mlx_xpm_file_to_image(map_game->mlx,
			"textures/empty.xpm", &map_game->img_w, &map_game->img_h);
	map_game->open_dor = mlx_xpm_file_to_image(map_game->mlx,
			"textures/open_dor.xpm", &map_game->img_w, &map_game->img_h);
	player_animation_case(map_game);
	map_game->wall = mlx_xpm_file_to_image(map_game->mlx,
			"textures/wall.xpm", &map_game->img_w, &map_game->img_h);
	if (!map_game->close_dor || !map_game->collect || !map_game->empty
		|| !map_game->open_dor || !map_game->player_left
		|| !map_game->player_right || !map_game->wall || !map_game->enemy)
		img_error(map_game);
}

void	my_map(t_my_struct *map_game)
{
	map_game->i = -1;
	game_img(map_game);
	while (map_game->map[++map_game->i])
	{
		map_game->j = -1;
		while (map_game->map[map_game->i][++map_game->j])
		{
			if (map_game->map[map_game->i][map_game->j] == '0')
				mlx_put_image_to_window(map_game->mlx, map_game->win,
					map_game->empty, map_game->j * 60, map_game->i * 60);
			else if (map_game->map[map_game->i][map_game->j] == '1')
				mlx_put_image_to_window(map_game->mlx, map_game->win,
					map_game->wall, map_game->j * 60, map_game->i * 60);
			else if (map_game->map[map_game->i][map_game->j] == 'C')
				c_game(map_game);
			else if (map_game->map[map_game->i][map_game->j] == 'P')
				p_game(map_game, map_game->i, map_game->j);
			else if (map_game->map[map_game->i][map_game->j] == 'E')
				e_game(map_game, map_game->i, map_game->j);
			else if (map_game->map[map_game->i][map_game->j] == 'N')
				n_game(map_game);
		}
	}
	put_string(map_game);
}

void	*init_project(t_my_struct *map_game)
{
	map_game->n_player = 0;
	map_game->n_collect = 0;
	map_game->move = 0;
	map_game->end = 0;
	map_game->mlx = mlx_init();
	if (!map_game->mlx)
		return (NULL);
	map_game->map_w = ft_strlen(map_game->map[0]) * 60;
	while (map_game->map[map_game->i])
		map_game->i++;
	map_game->map_h = map_game->i * 60;
	map_game->win = mlx_new_window(map_game->mlx, map_game->map_w,
			map_game->map_h, "so_long");
	if (!map_game->win)
		return (NULL);
	my_map(map_game);
	mlx_hook(map_game->win, 2, 0, &player_hooks, map_game);
	mlx_hook(map_game->win, 17, 0, &end_of_game, map_game);
	mlx_loop_hook(map_game->mlx, &animation_collect, map_game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_my_struct		game;
	t_my_struct2	game2;

	game.c_position = 1;
	game.p_position = 1;
	game.e_position = 1;
	game.open_dor = 0;
	game.loop = 0;
	game.top = 0;
	game2.i = 0;
	if (argc == 2 && valid_extension(argv[1]))
	{
		game.map = our_map(argv[1], game2);
		if (game.map != NULL && valid_map1(game.map) && valid_map2(game))
		{
			valid_map3(&game);
			valid_map4(&game, argv[1]);
		}
		else
			ft_printf("Error\nInvalid Map");
	}
	else
		ft_printf("Error\nInvalid Syntax");
}
