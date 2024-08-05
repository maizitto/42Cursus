/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:58:12 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 11:55:58 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_walkable(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x);
	map_y = (int)floor(y);
	return (map_x >= 0 && map_x < g->map.map_x && map_y >= 0
		&& map_y < g->map.map_y && g->map.map[map_y][map_x] != '1');
}

void	forward_move(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player.x + g->player.dir_x * g->player.move_speed;
	new_y = g->player.y + g->player.dir_y * g->player.move_speed;
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

	new_x = g->player.x - g->player.dir_x * g->player.move_speed;
	new_y = g->player.y - g->player.dir_y * g->player.move_speed;
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

	new_x = g->player.x + g->player.plane_x * g->player.move_speed;
	new_y = g->player.y + g->player.plane_y * g->player.move_speed;
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

	new_x = g->player.x - g->player.plane_x * g->player.move_speed;
	new_y = g->player.y - g->player.plane_y * g->player.move_speed;
	if (is_walkable(g, new_x, new_y))
	{
		g->player.x = new_x;
		g->player.y = new_y;
	}
}

