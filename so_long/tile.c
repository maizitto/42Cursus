/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:26 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/05 13:58:54 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_tile(char c)
{
	if (c == 48 || c == 49 || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

void	init_coin(t_game *game)
{
	game->star = (char **)malloc(sizeof(char *) * 5);
	game->star[0] = ft_strdup("textures/star0.xpm");
	game->star[1] = ft_strdup("textures/star1.xpm");
	game->star[2] = ft_strdup("textures/star2.xpm");
	game->star[3] = ft_strdup("textures/star3.xpm");
	game->star[4] = ft_strdup("textures/star4.xpm");
}

void	dec_coin(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	img_win(game, game->map.bg.image.img, y, x);
	game->mat[x][y] = '0';
	while (++i < game->map.ncoin)
	{
		if (game->map.coin[i].posx == x && game->map.coin[i].posy == y)
			game->map.coin[i].type = 'Q';
	}
}

void	set_tile(t_game *game, char type, int posx, int posy)
{
	if (type == 'P')
	{
		game->map.player.type = type;
		game->map.player.posx = posx;
		game->map.player.posy = posy;
	}
	else if (type == 'E')
	{
		game->map.exit[game->map.nexit].type = type;
		game->map.exit[game->map.nexit].posx = posx;
		game->map.exit[game->map.nexit].posy = posy;
		game->map.nexit++;
	}
	else if (type == 'C')
	{
		game->map.coin[game->map.ncoin].type = type;
		game->map.coin[game->map.ncoin].posx = posx;
		game->map.coin[game->map.ncoin].posy = posy;
		game->map.ncoin++;
	}
}
