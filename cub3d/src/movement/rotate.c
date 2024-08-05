/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:58:12 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 11:55:50 by mmasitto         ###   ########.fr       */
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

	rot_speed = rot_dir * g->player.rot_speed;
	upt_player(&g->player, cos(rot_speed), sin(rot_speed));
}
