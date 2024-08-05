/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:20:42 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 15:50:27 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	key_press(int keycode, t_game *g)
{
	if (keycode < 256)
		g->player.keys[keycode] = 1;
	else if (keycode == 0xFF51)
		g->player.keys[1] = 1;
	else if (keycode == 0xff53)
		g->player.keys[2] = 1;
	return (0);
}

static int	key_release(int keycode, t_game *g)
{
	if (keycode < 256)
		g->player.keys[keycode] = 0;
	else if (keycode == 0xff51)
		g->player.keys[1] = 0;
	else if (keycode == 0xff53)
		g->player.keys[2] = 0;
	return (0);
}

void	input(t_game *g)
{
	mlx_hook(g->data.win, 17, 0, ft_close_x, g);
	mlx_hook(g->data.win, 2, 1L << 0, key_press, g);
	mlx_hook(g->data.win, 3, 1L << 1, key_release, g);
}

int	movs(t_game *g)
{
	int	rotdir;

	if (g->player.keys['w'])
		forward_move(g);
	if (g->player.keys['s'])
		back_move(g);
	if (g->player.keys['a'])
		left_move(g);
	if (g->player.keys['d'])
		right_move(g);
	if (g->player.keys[1])
	{
		rotdir = -1;
		rotate(g, rotdir);
	}
	if (g->player.keys[2])
	{
		rotdir = 1;
		rotate(g, rotdir);
	}
	return (0);
}
