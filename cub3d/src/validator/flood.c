/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:43 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/08 16:01:18 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**dup_matrix(t_game *game)
{
	char	**dup;
	int		i;

	i = -1;
	dup = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	while (++i < game->map.rows)
		dup[i] = ft_strdup(game->map.map[i]);
	dup[i] = NULL;
	return (dup);
}

static void	flood_fill(t_game *g, int y, int x, char **visited)
{
	if (x > 0 && x < g->map.cols && y > 0 && y < g->map.rows
		&& g->map.map[y][x] != '1')
		visited[y][x] = '1';
	if (y + 1 < g->map.rows && visited[y + 1][x] != '1')
		flood_fill(g, y + 1, x, visited);
	if (x + 1 < g->map.cols && visited[y][x + 1] != '1')
		flood_fill(g, y, x + 1, visited);
	if (y - 1 >= 0 && visited[y - 1][x] != '1')
		flood_fill(g, y - 1, x, visited);
	if (y - 1 >= 0 && visited[y][x - 1] != '1')
		flood_fill(g, y, x - 1, visited);
}

void	check_path(t_game *g, t_sprite **space)
{
	char	**dup;
	int		i;

	i = -1;
	dup = dup_matrix(g);
	dup[(int)g->player.y][(int)g->player.x] = '1';
	flood_fill(g, (int)g->player.y, (int)g->player.x, dup);
	while (space[++i] && space[i]->type == 'x')
	{
		if (dup[(int)(space[i]->y)][(int)(space[i]->x)] == 0)
			quit(g, MAP_ERR, 1);
	}
	free_matrix((void **)dup, 0);
}
