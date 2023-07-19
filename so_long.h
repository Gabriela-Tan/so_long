/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:38 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 18:05:44 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
//# include <X11/X.h>
//# include <X11/keysym.h>
# include "./include/minilibx/mlx.h"
# include "./include/libft/libft.h"

# define GAME "GTA"
# define INSTRUCTIONS_1 "Welcome to GabTan Auto! (GTA for short)"
# define INSTRUCTIONS_2 "Toni wants you to get all the cash along the way, no questions asked."
# define INSTRUCTIONS_3 "Mind the cops! Get the cash and go hide in the garage!"
# define FAIL "Busted!"
# define SUCCESS "You made it!"

// xpm sprites
# define IMG_TILE "./xpm/0_img_tile_32.xpm"
# define IMG_WALL "./xpm/1_img_wall_32.xpm"
# define IMG_COLLECTIBLE "./xpm/2_img_cash_32.xpm"
# define IMG_EXIT "./xpm/3_img_exit_32.xpm"
# define IMG_ENEMY "./xpm/4_img_enemy_32.xpm"
# define IMG_PLAYER_R "./xpm/5_img_player_r_32.xpm"
# define IMG_PLAYER_L "./xpm/6_img_player_l_32.xpm"
# define IMG_PLAYER_U "./xpm/7_img_player_u_32.xpm"
# define IMG_PLAYER_D "./xpm/8_img_player_d_32.xpm"

/* Define all necessary keycodes to distinguish moves during game */
# define XK_a 0
# define XK_s 1
# define XK_d  2
# define XK_w 13
# define XK_q 12
# define XK_Escape 0x35

typedef struct s_grid
{
	int	col;
	int	row;
}	t_grid;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct s_xpm
{
	t_img	tile;
	t_img	wall;
	t_img	cash;
	t_img	exit;
	t_img	p_r;
	t_img	p_l;
	t_img	p_u;
	t_img	p_d;
	t_img	enemy;
}	t_xpm;

typedef struct s_game
{
	t_grid	player_on;
	t_grid	exit_on;
	t_grid	*enemy_on;
	char	**map;
	char	**map_check;
	char	player_dir;
	int		height;
	int		width;
	int		cash;
	int		exit;
	int		player;
	int		enemy;
	int		count_cash;
	int		count_exit;
}	t_game;

typedef struct s_set
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		moves;
	char	*arg;
	int		on;
	t_game	game;
	t_xpm	xpm;
}		t_set;

//initialize game
void	ft_fill_map(t_set *gta);
int		main(int argc, char *argv[]);
t_game	ft_map_read_content(char *file);

//window image handling
void	ft_player_sprite(t_set *gta, char character);
void	ft_enemy_sprite(t_set *gta);
void	ft_character_sprite(t_set *gta, char character, int row, int col);
void	sprites_init(t_set *gta);

//messages
int	ft_info_message(t_set *gta);
void	ft_win_lose_message(t_set *gta);
void	ft_start_message(t_set *gta);
void	ft_input_handling(int argc, char *argv[], t_set *gta);

//movement
void	ft_move_player(t_set *gta, int next_row, int next_col);
void	ft_quit_window(t_set *gta);
int		ft_keypress(int keycode, t_set *gta);
void	game_init(t_game *game);

//error handling
void	ft_check_valid_characters(t_game *game);
void	ft_check_enemy(t_game *game, int row, int col);
void	ft_check_invalid_elements(char **map, t_game *game, int row, int col);
int		ft_flood_fill(t_game *game, int row, int col);
void	ft_flood_path(t_game game);
void	ft_check_border_elements(char **map, t_game *game, int row, int col);
void	check_row_length(char **map, t_game *game);
void	ft_check_map(int code);

//free and end game
void	ft_clean_up(t_set *gta);
int		ft_quit(t_set *gta);
void	ft_free_map(char **map, char **line);
void	free_imgs(t_set *gta);

#endif
