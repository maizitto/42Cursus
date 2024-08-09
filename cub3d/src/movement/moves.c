/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:58:12 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 16:27:01 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_walkable(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0.25 || x >= g->map.cols - 1.25)
		return (0);
	if (y < 0.25 || y >= g->map.rows - 0.25)
		return (0);
	map_x = (int)x;
	map_y = (int)y;
	if (g->map.map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	forward_move(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player.x + g->player.dir_x * MOVE_SPEED;
	new_y = g->player.y + g->player.dir_y * MOVE_SPEED;
	if (is_walkable(g, new_x, new_y))
	{
		g->player.x = new_x;
		g->player.y = new_y;
	}
}

void	back_move(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player.x - g->player.dir_x * MOVE_SPEED;
	new_y = g->player.y - g->player.dir_y * MOVE_SPEED;
	if (is_walkable(g, new_x, new_y))
	{
		g->player.x = new_x;
		g->player.y = new_y;
	}
}

void	left_move(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player.x + g->player.dir_y * MOVE_SPEED;
	new_y = g->player.y - g->player.dir_x * MOVE_SPEED;
	if (is_walkable(g, new_x, new_y))
	{
		g->player.x = new_x;
		g->player.y = new_y;
	}
}

void	right_move(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player.x - g->player.dir_y * MOVE_SPEED;
	new_y = g->player.y + g->player.dir_x * MOVE_SPEED;
	if (is_walkable(g, new_x, new_y))
	{
		g->player.x = new_x;
		g->player.y = new_y;
	}
}
