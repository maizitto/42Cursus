/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:43 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/04 11:57:13 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**dup_matrix(t_game *game)
{
	char	**dup;
	int		i;

	i = -1;
	dup = (char **)malloc(sizeof(char *) * game->map.rows + 1);
	while (++i <= game->map.rows)
		dup[i] = ft_strdup(game->map.map[i]);
	return (dup);
}

static void	flood_fill(t_game *g, int x, int y, char **visited)
{
	if (x > 0 && x <= g->map.rows && y > 0 && y <= g->map.cols
		&& g->map.map[x][y] != '1')
		visited[x][y] = '1';
	if (x + 1 < g->map.rows && visited[x + 1][y] != '1')
		flood_fill(g, x + 1, y, visited);
	if (y + 1 < g->map.cols && visited[x][y + 1] != '1')
		flood_fill(g, x, y + 1, visited);
	if (x - 1 >= 0 && visited[x - 1][y] != '1')
		flood_fill(g, x - 1, y, visited);
	if (y - 1 >= 0 && visited[x][y - 1] != '1')
		flood_fill(g, x, y - 1, visited);
}

void	check_path(t_game *g, t_sprite *space)
{
	char	**dup;
	int		i;

	i = -1;
	dup = dup_matrix(g);
	dup[(int)g->player.x][(int)g->player.y] = '1';
	flood_fill(g, (int)g->player.x, (int)g->player.y, dup);
	while (space[++i].type == 'x')
	{
		if (dup[(int)(space[i].x)][(int)(space[i].y)] == 0)
			quit(MAP_ERR, 1);
	}
}
