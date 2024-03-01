/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:07:03 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/05 13:53:27 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.height = 0;
	game->map.path = NULL;
	game->map.width = 0;
	game->mat = NULL;
	game->map.ncoin = 0;
	game->map.coin_coll = 0;
	game->map.movcoin = 0;
	game->nmove = 0;
	game->loop = 0;
	game->npath = 0;
	game->aux_rand = 0;
	game->map.nexit = 0;
	return (1);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_close("MLX init failed", 1, game));
	game->win = mlx_new_window(game->mlx, (game->map.width) * 64,
			(game->map.height) * 64, "LIFE OF BRUCE");
	if (!game->win)
		return (ft_close("Window init failed", 1, game));
	if (!image_load(game))
		ft_close("Failing to load images", 1, game);
	if (!draw_map(game))
		ft_close("Failing to draw map", 1, game);
	mlx_loop_hook(game->mlx, *loop, game);
	mlx_key_hook(game->win, *input_key, game);
	mlx_hook(game->win, 17, 0, *ft_xclose, game);
	mlx_loop(game->mlx);
	ft_printf("culo");
	return (1);
}

int	loop(t_game *game)
{
	if (game->loop++ < 500)
		return (0);
	game->loop = 0;
	if (game->map.ncoin != game->map.coin_coll)
		loop_coin(game);
	else
	{
		mlx_destroy_image(game->mlx, game->map.exit[0].image.img);
		game->map.exit[0].image.img = mlx_xpm_file_to_image(game->mlx,
				"textures/fruit.xpm", &game->w, &game->h);
		img_win(game, game->map.bg.image.img, game->map.exit->posy,
			game->map.exit->posx);
		img_win(game, game->map.exit[0].image.img, game->map.exit->posy,
			game->map.exit->posx);
	}
	//draw_map(game);
	return (0);
}

void	loop_coin(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->mlx, game->map.coin[0].image.img);
	if (game->map.movcoin == 5)
		game->map.movcoin = 0;
	if (game->map.movcoin != 5)
	{
		game->map.coin[0].image.img = mlx_xpm_file_to_image(game->mlx,
				game->star[game->map.movcoin], &game->w, &game->h);
		game->map.movcoin++;
	}
	while (++i < game->map.ncoin)
	{
		if (game->map.coin[i].type != 'Q')
		{
			img_win(game, game->map.bg.image.img, game->map.coin[i].posy,
				game->map.coin[i].posx);
			img_win(game, game->map.coin[0].image.img, game->map.coin[i].posy,
				game->map.coin[i].posx);
		}
	}
}
/*
int	loop(t_game *game)
{
	if (game->loop++ < 500)
		return (0);
	game->loop = 0;
	loop_coin(game);
	if (game->map.ncoin == 0)
		game->map.exit.image.img = mlx_xpm_file_to_image(game->mlx,
				"textures/fruit.xpm", &game->w, &game->h);
	draw_map(game);
	return (0);
}

void	loop_coin(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.coin[0].image.img);
	if (game->map.movcoin == 5)
		game->map.movcoin = 0;
	if (game->map.movcoin != 5)
	{
		game->map.coin[0].image.img = mlx_xpm_file_to_image(game->mlx,
				game->star[game->map.movcoin], &game->w, &game->h);
		img_win(game, game->map.coin[0].image.img,
			game->map.coin[0].posx, game->map.coin[0].posy);
		game->map.movcoin++;
	}
}
*/
/*
void	loop_coin(t_game *game)
{
	char	*temp1;
	char	*temp;
	char	x[2];

	mlx_destroy_image(game->mlx, game->map.coin[0].image.img);
	if (game->map.movcoin == 5)
		game->map.movcoin = 0;
	if (game->map.movcoin != 5)
	{
		temp = ft_strdup(".xpm");
		temp1 = ft_strdup("textures/star");
		x[0] = (char)(game->map.movcoin + 48);
		x[1] = '\0';
		temp1 = ft_strjoin(temp1, x);
		temp = ft_strjoin(temp1, temp);
		game->map.coin[0].image.img = mlx_xpm_file_to_image(game->mlx,
				temp, &game->w, &game->h);
		img_win(game, game->map.coin[0].image.img,
			game->map.coin[0].posx, game->map.coin[0].posy);
		game->map.movcoin++;
	}
}*/