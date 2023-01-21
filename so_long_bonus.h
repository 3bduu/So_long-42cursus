/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:28:11 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 14:37:16 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct t_mystructt2
{
	char	**map;
	int		i;
	int		n;
	char	*ptr1;
	char	*ptr2;
	char	*ptr3;
	int		fd;
}			t_my_struct2;

typedef struct t_my_structt
{
	void	*mlx;
	void	*win;
	char	**map;
	int		loop;
	int		top;
	int		p_position;
	char	**mapp;
	char	**mapp3;
	int		i;
	int		j;
	int		r;
	int		c_position;
	int		e_position;
	int		left;
	int		right;
	int		map_h;
	int		map_w;
	int		player_x;
	int		player_y;
	int		n_player;
	int		n_exit;
	int		n_collect;
	void	*close_dor;
	int		end;
	void	*game_ovver;
	void	*collect;
	void	*enemy;
	void	*empty;
	void	*open_dor;
	void	*player_left;
	void	*player_right;
	int		move;
	void	*wall;
	int		img_w;
	int		img_h;
}			t_my_struct;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

//--------animation-------------//
int			animation_collect(t_my_struct *game);
void		animation_player(t_my_struct *game);
void		animation_player_lr(t_my_struct *game, char *str);
void		animation_super_player_lr(t_my_struct *game);
void		return_mlx_xpm1(t_my_struct *game, char *str);
void		return_mlx_xpm2(t_my_struct *game, char *str);
void		put_string(t_my_struct *map_game);
//------------------------------//
size_t		ft_strlen(const char *s);
char		**our_map(char *file, t_my_struct2 game);
int			check_collect3(char **mapp);
int			img_error(t_my_struct *so_long);
void		free_map(char **map);
void		p_game(t_my_struct *map_game, int i, int j);
void		e_game(t_my_struct *map_game, int i, int j);
void		n_game(t_my_struct *map_game);
void		c_game(t_my_struct *map_game);
void		player_animation_case(t_my_struct *map_game);
void		enemy_hooks(t_my_struct *game);
char		**our_map3(char *file, t_my_struct2 game);
char		**our_map2(char *file, t_my_struct2 game);
//--------------cheak_collect&&Exit..----------------//
int			check_collect(t_my_struct *map_game);
int			check_collect2(char **mapp);
int			check_collect3(char **mapp);
int			check_components(t_my_struct game);
void		floodfill(t_my_struct *game, int x, int y);
void		floodfill2(t_my_struct *game, int x, int y);
//----------------------------//
int			end_of_game(t_my_struct *so_long);
int			valid_map2(t_my_struct game);
void		valid_map3(t_my_struct *game);
void		valid_map4(t_my_struct *game, char *str);
//---------player_mov----------------------//
void		w_player(t_my_struct *player);
void		s_player(t_my_struct *player);
void		a_player(t_my_struct *player);
void		d_player(t_my_struct *player);
//----------------------------------//
void		*init_project(t_my_struct *map_game);
int			valid_extension(char *path);
int			valid_map1(char **map);
int			player_hooks(int key, t_my_struct *player);
void		my_map(t_my_struct *map_game);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
void		ft_bzero(void *s, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
//------------printf-----------------//
char		*ft_itoa(int n);
void		ft_putchar(int c, int *len);
void		ft_put_hex_min_nbr(unsigned int n, int *len);
void		ft_put_hex_maj_nbr(unsigned int n, int *len);
void		ft_put_address(unsigned long n, int *len);
void		ft_put_sign(int c, int *len);
void		ft_putnbr(int n, int *len);
void		ft_putstr(char *s, int *len);
void		ft_put_uns_nbr(unsigned int n, int *len);
int			ft_printf(const char *print, ...);
#endif
