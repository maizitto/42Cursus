/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:20:42 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 13:01:36 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307 || keycode == 53)
		ft_close_x(g);
	if (keycode < 256)
	{
		g->player.keys[keycode] = 1;
	}
	else if (keycode == 0xFF51)
		g->player.keys[254] = 1;
	else if (keycode == 0xff53)
		g->player.keys[255] = 1;
	return (0);
}

static int	key_release(int keycode, t_game *g)
{
	if (keycode < 256)
	{
		g->player.keys[keycode] = 0;
	}
	else if (keycode == 0xff51)
		g->player.keys[254] = 0;
	else if (keycode == 0xff53)
		g->player.keys[255] = 0;
	return (0);
}

// static int	key_press(int keycode, t_game *g)
// {
// 	if (keycode == 65307)
// 		ft_close_x(g);
// 	if (keycode < 256)
// 	{
// 		if (keycode == KEY_W)
// 			keycode = 'w';
// 		if (keycode == KEY_S)
// 			keycode = 's';
// 		if (keycode == KEY_A)
// 			keycode = 'a';
// 		if (keycode == KEY_D)
// 			keycode = 'd';
// 		g->player.keys[keycode] = 1;
// 	}
// 	return (0);
// }

// static int	key_release(int keycode, t_game *g)
// {
// 	if (keycode < 256)
// 	{
// 		if (keycode == KEY_W)
// 			keycode = 'w';
// 		if (keycode == KEY_S)
// 			keycode = 's';
// 		if (keycode == KEY_A)
// 			keycode = 'a';
// 		if (keycode == KEY_D)
// 			keycode = 'd';
// 		g->player.keys[keycode] = 0;
// 	}
// 	return (0);
// }

void	input(t_game *g)
{
	mlx_hook(g->data.win, 17, 0, *ft_close_x, g);
	mlx_hook(g->data.win, 2, 1L << 0, key_press, g);
	mlx_hook(g->data.win, 3, 1L << 1, key_release, g);
	if (BONUS)
		mlx_hook(g->data.win, 6, 1L << 6, mouse_move, g);
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
	if (g->player.keys[123] || g->player.keys[254])
	{
		rotdir = -1;
		rotate(g, rotdir);
	}
	if (g->player.keys[124] || g->player.keys[255])
	{
		rotdir = 1;
		rotate(g, rotdir);
	}
	return (0);
}
