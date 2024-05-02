/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:16:25 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/30 12:06:50 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_matrix(t_game *game)
{
	char	**dup;
	int		i;

	i = -1;
	dup = (char **)malloc(sizeof(char *) * game->map.height);
	while (++i < game->map.height)
		dup[i] = ft_strdup(game->mat[i]);
	return (dup);
}

static void	aux_check_path(t_game *game, int x, int y, char **visited)
{
	if (x >= 0 && x < game->map.height - 1 && y >= 0 && y < game->map.width - 1
		&& (game->mat[x][y] == 48 || game->mat[x][y] == 'C'
		|| game->mat[x][y] == 'E') && visited[x][y] != 49)
		visited[x][y] = 49;
	if (visited[x + 1][y] != 49 && visited[x + 1][y] != 'P')
		aux_check_path(game, x + 1, y, visited);
	if (visited[x][y + 1] != 49 && visited[x][y + 1] != 'P')
		aux_check_path(game, x, y + 1, visited);
	if (visited[x - 1][y] != 49 && visited[x - 1][y] != 'P')
		aux_check_path(game, x - 1, y, visited);
	if (visited[x][y - 1] != 49 && visited[x][y - 1] != 'P')
		aux_check_path(game, x, y - 1, visited);
	if (game->mat[x][y] == 48)
	{
		game->npath--;
		game->pos_path[game->npath].posx = x;
		game->pos_path[game->npath].posy = y;
		game->pos_path[game->npath].type = 48;
	}
}

static int	check_coin(t_game *game, char **dup)
{
	int	i;

	i = -1;
	while (++i < game->map.ncoin)
	{
		if (dup[game->map.coin[i].posx][game->map.coin[i].posy] != 49)
			return (0);
	}
	return (1);
}

void	check_path(t_game *game)
{
	char	**dup;
	int		i;

	i = -1;
	dup = dup_matrix(game);
	game->pos_path = (t_tile *)malloc(sizeof(t_tile) * game->npath);
	if (!game->pos_path)
		ft_close("Error on check_path", 2, game);
	game->aux_rand = game->npath;
	aux_check_path(game, game->map.player.posx, game->map.player.posy, dup);
	while (++i < game->map.nexit)
	{
		if (dup[game->map.exit[i].posx][game->map.exit[i].posy] != 49)
		{
			clean_matrix(dup, game);
			ft_close("Path to exit not valid", 2, game);
		}
	}
	if (!check_coin(game, dup))
	{
		clean_matrix(dup, game);
		ft_close("Path to coins not valid", 2, game);
	}
	clean_matrix(dup, game);
}
