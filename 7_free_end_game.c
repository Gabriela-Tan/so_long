/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free_end_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:02:02 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 17:51:45 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Free allocated memory */
void	ft_clean_up(t_set *gta)
{
	int	i;

	i = 0;
	free(gta->mlx);
	while (gta->game.map[i])
	{
		free(gta->game.map[i]);
		free(gta->game.map_check[i]);
		i++;
	}
	free(gta->game.map[i]);
	free(gta->game.map_check[i]);
	free(gta->game.map);
	free(gta->game.map_check);
	free_imgs(gta);
}

/* Quit the game */
int	ft_quit(t_set *gta)
{
	if (gta)
	{
		mlx_destroy_window(gta->mlx, gta->mlx_win);
	//	mlx_destroy_display(gta->mlx);
		ft_clean_up(gta);
	}
	exit(0);
}

/* free memory for the map */
void	ft_free_map(char **map, char **line)
{
	free(*map);
	free(*line);
}

void	free_imgs(t_set *gta)
{
	free(gta->game.enemy_on);
	free(gta->xpm.tile.img);
	free(gta->xpm.wall.img);
	free(gta->xpm.cash.img);
	free(gta->xpm.exit.img);
	free(gta->xpm.enemy.img);
	free(gta->xpm.p_r.img);
	free(gta->xpm.p_l.img);
	free(gta->xpm.p_u.img);
	free(gta->xpm.p_d.img);
}
