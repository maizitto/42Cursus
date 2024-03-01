/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:26:36 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/01 16:30:40 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	aux_map(t_game *game, int j, int i)
{
	void	*temp;

	img_win(game, game->map.bg.image.img, i, j);
	if (game->mat[j][i] == 'P')
		img_win(game, game->map.player.image.img, i, j);
	else if (game->mat[j][i] == 'E')
		img_win(game, game->map.exit[0].image.img, i, j);
	else if (game->mat[j][i] == 'C')
		img_win(game, game->map.coin[0].image.img, i, j);
	else if (game->mat[j][i] == '1')
		img_win(game, game->map.wall.image.img, i, j);
	else if (game->mat[j][i] == 'X')
		img_win(game, game->map.enemy.image.img, i, j);
	temp = mlx_xpm_file_to_image(game->mlx,
			"textures/score.xpm", &game->w, &game->h);
	img_win(game, temp, 0, 0);
}

int	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	*move;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			aux_map(game, i, j);
		}
	}
	move = ft_itoa(game->nmove);
	mlx_string_put(game->mlx, game->win, 5, 10, 0x00FFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 25, 35, 0x00FFFFFF, move);
	free (move);
	return (1);
}

int	image_load(t_game *game)
{
	init_coin(game);
	game->map.bg.image.img = mlx_xpm_file_to_image(game->mlx,
			"textures/bg1.xpm", &game->w, &game->h);
	game->map.coin[0].image.img = mlx_xpm_file_to_image(game->mlx,
			game->star[0], &game->w, &game->h);
	game->map.wall.image.img = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall.xpm", &game->w, &game->h);
	game->map.player.image.img = mlx_xpm_file_to_image(game->mlx,
			"textures/kn1.xpm", &game->w, &game->h);
	game->map.exit[0].image.img = mlx_xpm_file_to_image(game->mlx,
			"textures/Exit.xpm", &game->w, &game->h);
	game->map.enemy.image.img = mlx_xpm_file_to_image(game->mlx,
			"textures/en.xpm", &game->w, &game->h);
	if (!game->map.bg.image.img || !game->map.coin[0].image.img
		|| !game->map.wall.image.img || !game->map.player.image.img
		|| !game->map.exit[0].image.img || !game->map.enemy.image.img)
		return (0);
	return (1);
}

int	img_win(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, (x) * game->h,
		(y) * game->h);
	return (1);
}
