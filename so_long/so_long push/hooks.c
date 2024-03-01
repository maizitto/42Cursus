/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:14:02 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/07 10:52:46 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ch(t_game *game, int x, int y)
{
	if (game->mat[x][y] == 1)
		return (0);
	if (game->mat[x][y] == 'X')
		ft_close("WASTED", 9, game);
	if (game->map.coin_coll == game->map.ncoin && game->mat[x][y] == 'E')
	{
		ft_printf("\nCongrats\nYou completed the game with %d moves\n",
			++game->nmove);
		ft_close("Bye\n", 0, game);
		return (0);
	}
	else if (game->map.coin_coll != game->map.ncoin && game->mat[x][y] == 'E')
	{
		ft_printf("You are missing some coins\n");
		return (0);
	}
	if (game->mat[x][y] == 'C')
	{
		ft_printf("Coin collected!!!!!!\n");
		game->map.coin_coll++;
		dec_coin(game, x, y);
	}
	ft_printf("You moved %d times\n", ++game->nmove);
	return (1);
}

static int	check_exit(int key, t_game *game)
{
	if (key == 53)
		ft_xclose(game);
	return (1);
}

int	input_key(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.posx;
	y = game->map.player.posy;
	if ((key == 126 || key == 13) && move_pg(game, x, y, key))
		game->map.player.posx--;
	if ((key == 125 || key == 1) && move_pg(game, x, y, key))
		game->map.player.posx++;
	if ((key == 124 || key == 2) && move_pg(game, x, y, key))
		game->map.player.posy++;
	if ((key == 123 || key == 0) && move_pg(game, x, y, key))
		game->map.player.posy--;
	check_exit(key, game);
	return (0);
}

static void	update(t_game *g, int new_x, int new_y, int move)
{
	char	*display;
	char	*temp;

	g->mat[g->map.player.posx][g->map.player.posy] = 48;
	g->mat[new_x][new_y] = 'P';
	if (move == 1)
		g->map.player.image.img = mlx_xpm_file_to_image(g->mlx,
				"textures/kn1.xpm", &g->w, &g->h);
	else if (move == 0)
		g->map.player.image.img = mlx_xpm_file_to_image(g->mlx,
				"textures/kn2.xpm", &g->w, &g->h);
	img_win(g, g->map.bg.image.img, g->map.player.posy, g->map.player.posx);
	img_win(g, g->map.player.image.img, new_y, new_x);
	temp = mlx_xpm_file_to_image(g->mlx,
			"textures/score.xpm", &g->w, &g->h);
	img_win(g, temp, 0, 0);
	display = ft_itoa(g->nmove);
	mlx_string_put(g->mlx, g->win, 5, 10, 0x00FFFFFF, "MOVES: ");
	mlx_string_put(g->mlx, g->win, 25, 35, 0x00FFFFFF, display);
	free (display);
}

int	move_pg(t_game *g, int x, int y, int m)
{
	if ((m == 123 || m == 0) && g->mat[x][y - 1] != 49 && ch(g, x, y - 1))
	{
		update(g, x, y - 1, 0);
		return (1);
	}
	else if ((m == 124 || m == 2) && g->mat[x][y + 1] != 49 && ch(g, x, y + 1))
	{
		update(g, x, y + 1, 1);
		return (1);
	}
	else if ((m == 125 || m == 1) && g->mat[x + 1][y] != 49 && ch(g, x + 1, y))
	{
		update(g, x + 1, y, -1);
		return (1);
	}
	else if ((m == 126 || m == 13) && g->mat[x - 1][y] != 49 && ch(g, x - 1, y))
	{
		update(g, x - 1, y, -1);
		return (1);
	}
	return (0);
}
