/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:07 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 17:52:39 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fill the map with corresponding tiles */
void	ft_fill_map(t_set *gta)
{
	int	row;
	int	col;

	row = 0;
	while (gta->game.map[row])
	{
		col = 0;
		while (gta->game.map[row][col])
		{
			ft_character_sprite(gta, gta->game.map[row][col], row, col);
			col++;
		}
		row++;
	}
}

int	main(int argc, char *argv[])
{
	t_set	gta;

	ft_input_handling(argc, argv, &gta);
	gta.game = ft_map_read_content(gta.arg);
	gta.height = 32 * (gta.game.height);
	gta.width = 32 * (gta.game.width - 1);
	gta.mlx = mlx_init();
	gta.mlx_win = mlx_new_window(gta.mlx, gta.width, gta.height, GAME);
	gta.on = 1;
	gta.moves = 0;
	sprites_init(&gta);
	mlx_loop_hook(gta.mlx, ft_info_message, &gta);
	mlx_hook(gta.mlx_win, 2, 1L << 2, ft_keypress, &gta);
	mlx_hook(gta.mlx_win, 17, 1L << 0, ft_quit, &gta);
	mlx_loop(gta.mlx);
}

/* Read the map file and check if it's valid */
t_game	ft_map_read_content(char *file)
{
	t_game	game_map;
	int		fd;
	char	*map;
	char	*line;

	fd = open(file, O_RDONLY);
	map = ft_strdup("");
	line = get_next_line(fd);
	game_init(&game_map);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
		game_map.height++;
	}
	game_map.map = ft_split(map, '\n');
	game_map.map_check = ft_split(map, '\n');
	if (game_map.map[0])
		game_map.width = ft_strlen(game_map.map[0]);
	check_row_length(game_map.map, &game_map);
	ft_free_map(&map, &line);
	close(fd);
	return (game_map);
}
