/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/08 19:15:45 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(char *str, int flag)
{
	int	x;

	if (flag)
		x = write(1, "Error\n", 6);
	x = write(1, str, ft_strlen(str));
	(void)x;
	return ;
}

void	quit(t_game *game, char *str, int flag)
{
	(void)flag;
	if (!game)
		ft_error(str, 1);
	else
	{
		ft_error(str, 0);
		free_game(game);
		if (game->data.mlx && game->data.win)
			mlx_destroy_window(game->data.mlx, game->data.win);
		if (game->data.mlx)
		{
			mlx_destroy_display(game->data.mlx);
			mlx_loop_end(game->data.mlx);
			free(game->data.mlx);
		}
	}
	exit(0);
}

int	ft_close_x(t_game *game)
{
	quit(game, "Bye Bye", 9);
	return (0);
}

void	reset_matrix(int **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i < RES_Y)
	{
		j = -1;
		while (++j < RES_X)
		{
			matrix[i][j] = 0;
		}
	}
}
