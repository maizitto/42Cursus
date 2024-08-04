/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:53:06 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/04 12:17:25 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_up_down(t_game *g, int j, int i, int k)
{
	k = ft_strlen(g->map.map[0]) - 1;
	while (++j < k)
	{
		if (g->map.map[0][j] == ' ')
		{
			if (g->map.map[0][j + 1] == '1' && g->map.map[0][j - 1] == '1'
				&& g->map.map[1][j] == '1')
				g->map.map[0][j] = '1';
		}
		else if (g->map.map[0][j] != '1')
			quit(MAP_ERR, 1);
	}
	k = g->map.rows;
	while (++i < (int)(ft_strlen(g->map.map[k]) - 1))
	{
		if (g->map.map[k][i] == ' ')
		{
			if (g->map.map[k][i + 1] == '1' && g->map.map[k][i - 1] == '1'
				&& g->map.map[k - 1][i] != '0')
				g->map.map[k][i] = '1';
		}
		else if (g->map.map[k][i] != '1')
			quit(MAP_ERR, 1);
	}
}

static void	remove_space(t_game *g, int j, int i)
{
	while (++i < g->map.rows)
	{
		j = 0;
		while (g->map.map[i][j] != '1')
		{
			if (g->map.map[i][j] == 8 || g->map.map[i][j] == 32)
				g->map.map[i][j] = '1';
			if (g->map.map[i][j] != '1')
				quit(MAP_ERR, 1);
			j++;
		}
		j = ft_strlen(g->map.map[i]) - 2;
		while (g->map.map[i][j] != '1')
		{
			if (g->map.map[i][j] == 8 || g->map.map[i][j] == 32)
				g->map.map[i][j] = '1';
			if (g->map.map[i][j] != '1')
				quit(MAP_ERR, 1);
			j--;
		}
	}
	check_up_down(g, -1, -1, 0);
}

static void	aux_set_tile(t_sprite *sprite, int i, int j, t_game *game)
{
	if (!sprite)
	{
		game->player.x = i;
		game->player.y = j;
		game->player.dir = game->map.map[i][j];
	}
	else
	{
		sprite->x = i;
		sprite->y = j;
		if (game->map.map[i][j] == ' ')
			sprite->type = 'x';
		else
			sprite->type = game->map.map[i][j];
	}
}

static void	set_tile(t_game *g, t_sprite *space, int k)
{
	int	i;
	int	j;

	i = 0;
	while (++i < g->map.rows)
	{
		j = 0;
		while (++j < (int)ft_strlen(g->map.map[i]))
		{
			if (g->map.map[i][j] == 'N' || g->map.map[i][j] == 'S'
				|| g->map.map[i][j] == 'E' || g->map.map[i][j] == 'W')
				aux_set_tile(NULL, i, j, g);
			if (g->map.map[i][j] == ' ')
				aux_set_tile(&space[k++], i, j, g);
			if (g->map.map[i][j] == 'C')
				aux_set_tile(&g->elements.collectibles[g->elements.c_count++],
					i, j, g);
			if (g->map.map[i][j] == 'D')
				aux_set_tile(&g->elements.doors[g->elements.d_count++],
					i, j, g);
			if (g->map.map[i][j] == 'E')
				aux_set_tile(&g->elements.enemies[g->elements.e_count++],
					i, j, g);
		}
	}
}

void	parse_map(t_game *game)
{
	t_sprite	space[100];
	int			i;
	int			j;

	i = -1;
	j = -1;
	remove_space(game, 0, -1);
	while (++i < game->map.rows)
	{
		while (++j < (int)ft_strlen(game->map.map[i]))
		{
			if (game->map.map[i][j] == 'C')
				game->elements.c_count++;
			if (game->map.map[i][j] == 'D')
				game->elements.d_count++;
			if (game->map.map[i][j] == 'E')
				game->elements.e_count++;
		}
	}
	init_elements(game);
	set_tile(game, space, 0);
	check_path(game, space);
}
