/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_window_image_handling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:00:16 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 18:06:23 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_sprite(t_set *gta, char character)
{
	if (character == 'P')
	{
		if (gta->game.player_dir == 'w')
			mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.p_d.img,
				(gta->width / gta->game.width) * gta->game.player_on.col,
				(gta->height / gta->game.height) * gta->game.player_on.row);
		else if (gta->game.player_dir == 'a')
			mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.p_l.img,
				(gta->width / gta->game.width) * gta->game.player_on.col,
				(gta->height / gta->game.height) * gta->game.player_on.row);
		else if (gta->game.player_dir == 's')
			mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.p_u.img,
				(gta->width / gta->game.width) * gta->game.player_on.col,
				(gta->height / gta->game.height) * gta->game.player_on.row);
		else
			mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.p_r.img,
				(gta->width / gta->game.width) * gta->game.player_on.col,
				(gta->height / gta->game.height) * gta->game.player_on.row);
	}
}

void	ft_enemy_sprite(t_set *gta)
{
	int i = 0;
	while (i < gta->game.enemy)
	{
		mlx_put_image_to_window(gta->mlx, gta->mlx_win,
			gta->xpm.enemy.img,
			(gta->width / gta->game.width) * gta->game.enemy_on[i].col,
			(gta->height / gta->game.height) * gta->game.enemy_on[i].row);
		i++;
	}
}

void	ft_character_sprite(t_set *gta, char character, int row, int col)
{
	if (character == '0')
		mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.tile.img,
			(gta->width / gta->game.width) * col,
			(gta->height / gta->game.height) * row);
	else if (character == '1')
		mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.wall.img,
			(gta->width / gta->game.width) * col,
			(gta->height / gta->game.height) * row);
	else if (character == 'C')
		mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.cash.img,
			(gta->width / gta->game.width) * col,
			(gta->height / gta->game.height) * row);
	else if (character == 'E' || character == 'O')
		mlx_put_image_to_window(gta->mlx, gta->mlx_win, gta->xpm.exit.img,
			(gta->width / gta->game.width) * col,
			(gta->height / gta->game.height) * row);
	else if (character == 'X')
		ft_enemy_sprite(gta);
	ft_player_sprite(gta, character);
}

void	sprites_init(t_set *gta)
{
	gta->xpm.tile.img = mlx_xpm_file_to_image(gta->mlx, IMG_TILE,
			&(gta->xpm.tile.width), &(gta->xpm.tile.height));
	gta->xpm.wall.img = mlx_xpm_file_to_image(gta->mlx, IMG_WALL,
			&(gta->xpm.wall.width), &(gta->xpm.wall.height));
	gta->xpm.cash.img = mlx_xpm_file_to_image(gta->mlx, IMG_COLLECTIBLE,
			&(gta->xpm.cash.width), &(gta->xpm.cash.height));
	gta->xpm.exit.img = mlx_xpm_file_to_image(gta->mlx, IMG_EXIT,
			&(gta->xpm.exit.width), &(gta->xpm.exit.height));
	gta->xpm.enemy.img = mlx_xpm_file_to_image(gta->mlx, IMG_ENEMY,
			&(gta->xpm.enemy.width), &(gta->xpm.enemy.height));
	gta->xpm.p_r.img = mlx_xpm_file_to_image(gta->mlx, IMG_PLAYER_R,
			&(gta->xpm.p_r.width), &(gta->xpm.p_r.height));
	gta->xpm.p_l.img = mlx_xpm_file_to_image(gta->mlx, IMG_PLAYER_L,
			&(gta->xpm.p_l.width), &(gta->xpm.p_l.height));
	gta->xpm.p_u.img = mlx_xpm_file_to_image(gta->mlx, IMG_PLAYER_U,
			&(gta->xpm.p_u.width), &(gta->xpm.p_u.height));
	gta->xpm.p_d.img = mlx_xpm_file_to_image(gta->mlx, IMG_PLAYER_D,
			&(gta->xpm.p_d.width), &(gta->xpm.p_d.height));
}
