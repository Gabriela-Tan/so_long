/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:02:20 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 17:45:28 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Update player position based on the next move */
void	ft_move_player(t_set *gta, int next_row, int next_col)
{
	if (((*gta).game.map[(*gta).game.player_on.row + 
		next_row][(*gta).game.player_on.col + next_col] != '1')
	&& ((*gta).game.map[(*gta).game.player_on.row+ 
		next_row][(*gta).game.player_on.col + next_col] != 'E'))
	{
		if ((*gta).game.map[(*gta).game.player_on.row + 
			next_row][(*gta).game.player_on.col + next_col] == 'C')
			(*gta).game.cash--;
		(*gta).game.map[(*gta).game.player_on.row][(*gta).game.player_on.col] = '0';
		(*gta).game.map[(*gta).game.player_on.row +
			next_row][(*gta).game.player_on.col + next_col] = 'P';
		(*gta).game.player_on.row += next_row;
		(*gta).game.player_on.col += next_col;
		(*gta).moves++;
	}
	if ((*gta).game.cash == 0)
		(*gta).game.map[(*gta).game.exit_on.row][(*gta).game.exit_on.col] = 'O';
}

/* Handle quitting the window */
void	ft_quit_window(t_set *gta)
{
	mlx_destroy_window(gta->mlx, gta->mlx_win);
	ft_clean_up(gta);
	exit(0);
}

/* Modified ft_keypress function */
int	ft_keypress(int keycode, t_set *gta)
{
	if (keycode == XK_Escape || keycode == XK_q)
		ft_quit_window(gta);
	else if (gta->on && keycode == XK_w)
	{
		ft_move_player(gta, -1, 0);
		gta->game.player_dir = 'w';
	}
	else if (gta->on && keycode == XK_a)
	{
		ft_move_player(gta, 0, -1);
		gta->game.player_dir = 'a';
	}
	else if (gta->on && keycode == XK_s)
	{
		ft_move_player(gta, 1, 0);
		gta->game.player_dir = 's';
	}
	else if (gta->on && keycode == XK_d)
	{
		ft_move_player(gta, 0, 1);
		gta->game.player_dir = 'd';
	}
	return (0);
}

/* Initialize the variables, save the position fo the player and exit */
void	game_init(t_game *game)
{
	(*game).map = NULL;
	(*game).height = 0;
	(*game).width = 0;
	(*game).cash = 0;
	(*game).exit = 0;
	(*game).player = 0;
	(*game).enemy = 0;
	(*game).player_on.row = 0;
	(*game).player_on.col = 0;
	(*game).exit_on.row = 0;
	(*game).exit_on.col = 0;
	(*game).player_dir = 'd';
	(*game).enemy = 0;
	(*game).enemy_on = (t_grid*)malloc(sizeof(t_grid)); 
}
