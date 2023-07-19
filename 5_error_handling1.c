/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_error_handling1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:28:17 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 17:52:12 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map contains valid characters */
void	ft_check_valid_characters(t_game *game)
{
	if ((*game).exit != 1 || (*game).player != 1 || (*game).cash < 1)
		ft_check_map(1);
}

/* Function to check for enemies */
void ft_check_enemy(t_game *game, int row, int col) 
{
	game->enemy_on = (t_grid*)realloc(game->enemy_on,
		(game->enemy + 1) * sizeof(t_grid));
	game->enemy_on[game->enemy].col = col;
	game->enemy_on[game->enemy].row = row;
	game->enemy++;
}

/* Check if elements are valid */
void ft_check_invalid_elements(char **map, t_game *game, int row, int col)
{
	if (map[row][col] == 'P')
	{
		game->player++;
		game->player_on.col = col;
		game->player_on.row = row;
	}
	else if (map[row][col] == 'E')
	{
		game->exit++;
		game->exit_on.col = col;
		game->exit_on.row = row;
	}
	else if (map[row][col] == 'X')
		ft_check_enemy(game, row, col);
	else if (map[row][col] == 'C')
		game->cash++;
	else if (map[row][col] != '0' && map[row][col] != '1')
		ft_check_map(2);
}

/* Check if it's possible to collect all cash and reach exit */
int	ft_flood_fill(t_game *game, int row, int col)
{
	if ((*game).map_check[row][col] == 'F'
		|| (*game).map_check[row][col] == '1')
		return (0);
	if ((*game).map_check[row][col] == 'C')
		(*game).count_cash--;
	if ((*game).map_check[row][col] == 'E')
		(*game).count_exit--;
	if ((*game).map_check[row][col] == 'E')
	{
		(*game).map_check[row][col] = 'F';
		return (0);
	}
	else
		(*game).map_check[row][col] = 'F';
	ft_flood_fill(game, row + 1, col);
	ft_flood_fill(game, row - 1, col);
	ft_flood_fill(game, row, col + 1);
	ft_flood_fill(game, row, col - 1);
	return (1);
}

/* Check if it's possible to collect all cash and reach exit */
void	ft_flood_path(t_game game)
{
	game.count_cash = game.cash;
	game.count_exit = game.exit;
	ft_flood_fill(&game, game.player_on.row, game.player_on.col);
	if (game.count_cash != 0 || game.count_exit != 0)
		ft_check_map(3);
}
