/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:58:12 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/06 14:37:11 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	upt_player(t_player *p, double cos_rot, double sin_rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos_rot - p->dir_y * sin_rot;
	p->dir_y = old_dir_x * sin_rot + p->dir_y * cos_rot;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos_rot - p->plane_y * sin_rot;
	p->plane_y = old_plane_x * sin_rot + p->plane_y * cos_rot;
}

void	rotate(t_game *g, double rot_dir)
{
	double	rot_speed;

	rot_speed = rot_dir * ROT_SPEED;
	upt_player(&g->player, cos(rot_speed), sin(rot_speed));
}

int	mouse_move(int x, int y, t_game *g)
{
	if (x > RES_X - 20)
	{
		x = RES_X - 20;
		mlx_mouse_move(g->data.mlx, g->data.win, x, y);
	}
	if (x < 20)
	{
		x = 20;
		mlx_mouse_move(g->data.mlx, g->data.win, x, y);
	}
	if (x == g->mouse)
		return (0);
	else if (x < g->mouse)
		rotate(g, -1);
	else if (x > g->mouse)
		rotate(g, 1);
	g->mouse = x;
	return (0);
}
