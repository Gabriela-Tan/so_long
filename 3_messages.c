/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_messages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:52:49 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/19 05:39:22 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/* Print moves and winning message, track exit and enemy encounter */
int	ft_info_message(t_set *gta)
{
	char	*move;

	move = ft_itoa(gta->moves);
	mlx_clear_window(gta->mlx, gta->mlx_win);
	ft_fill_map(gta);
	mlx_string_put(gta->mlx, gta->mlx_win, 10, 10, 0xFFFFFFFF, "Moves: ");
	mlx_string_put(gta->mlx, gta->mlx_win, 55, 10, 0xFFFFFFFF, move);
	free(move);
	ft_start_message(gta);
	ft_win_lose_message(gta);
	return (0);
}

/* Print corresponding message and stop the game */
void	ft_win_lose_message(t_set *gta)
{
	int	i;

	i = 0;
	while (i < gta->game.enemy)
	{
		if (gta->game.player_on.col == gta->game.enemy_on[i].col
			&& gta->game.player_on.row == gta->game.enemy_on[i].row)
		{
			mlx_string_put(gta->mlx, gta->mlx_win, 
			gta->width / 2 - 40, gta->height / 2, 0xFFFFFFFF, FAIL);
				gta->on = 0;
			break;
		}
		i++;
	}
	if (gta->game.player_on.col == gta->game.exit_on.col
		&& gta->game.player_on.row == gta->game.exit_on.row)
	{
		mlx_string_put(gta->mlx, gta->mlx_win, 
			gta->width / 2 - 40, gta->height / 2, 0xFFFFFFFF, SUCCESS);
		gta->on = 0;
	}
}

/* Print start message */
void	ft_start_message(t_set *gta)
{
	mlx_string_put(gta->mlx, gta->mlx_win, 10, 30, 0xFFFFFFFF, INSTRUCTIONS_1);
	mlx_string_put(gta->mlx, gta->mlx_win, 10, 45, 0xFFFFFFFF, INSTRUCTIONS_2);
	mlx_string_put(gta->mlx, gta->mlx_win, 10, 60, 0xFFFFFFFF, INSTRUCTIONS_3);
}


// /* Check map format and number of arguments */
// void	ft_input_handling(int argc, char *argv[], t_set *gta)
// {
// int	len;

// len = ft_strlen(argv[1]);
// if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
// {
// ft_printf("Error! Map is not in .ber format.\n");
// exit (0);
// }
// if (argc != 2 || !argv[1])
// {
// ft_printf("Error! Wrong number of arguments.\n");
// exit (0);
// }
// gta->arg = argv[1];
// }
void	ft_input_handling(int argc, char *argv[], t_set *gta)
{
	if (argc != 2)
	{
		ft_printf("Error! Wrong number of arguments.\n");
		exit (0);
	}
	int	len;

	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error! Map is not in .ber format.\n");
		exit (0);
	}
	gta->arg = argv[1];
}

