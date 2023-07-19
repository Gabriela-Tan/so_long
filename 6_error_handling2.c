/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_error_handling2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:28:17 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 17:59:34 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the border elements are '1' */
void	ft_check_border_elements(char **map, t_game *game, int row, int col)
{
	if (row == 0 || row == game->height - 1 || col == 0 || col == game->width - 1)
	{
		if (map[row][col] != '1')
			ft_check_map(4);
	}
}

/* Check if the map rows are the same length */
void	check_row_length(char **map, t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		if (ft_strlen(map[0]) != ft_strlen(map[row]))
			ft_check_map(5);
		while (map[row][col])
		{
			ft_check_border_elements(map, game, row, col);
			ft_check_invalid_elements(map, game, row, col);
			col++;
		}
		row++;
	}
	ft_check_valid_characters(game);
	ft_flood_path(*game);
}

/* Print relevant error messages and exit the game */
void	ft_check_map(int code)
{
	if (code == 1)
		ft_printf("Error! Game characters are incomplete\n");
	else if (code == 2)
		ft_printf("Error! Some game elements are invalid\n");
	else if (code == 3)
		ft_printf("Error! The game is not playable.\n");
	else if (code == 4)
		ft_printf("Error! Walls are not complete.\n");
	else if (code == 5)
		ft_printf("Error! Map rows are not the same length.\n");
	exit (0);
}

