/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:43 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 11:25:26 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_minimap(t_game *g)
{
	init_img_details(g, &g->minimap.img, MINI_RES_X - 5, MINI_RES_Y - 5);
	g->minimap.cell_h = (double)(MINI_RES_Y / g->map.rows);
	g->minimap.cell_w = (double)(MINI_RES_X / g->map.cols);
}

void	draw_player(t_game *g, double x, double y)
{
	double	info[3];
	double	radius;

	info[0] = x * g->minimap.cell_w;
	info[1] = y * g->minimap.cell_h;
	radius = g->minimap.cell_w / 3;
	info[2] = radius;
	draw_circle(&g->minimap.img, info, 0x00FF00);
}

void	draw_minimap(t_game *g)
{
	int	dim[2];

	dim[0] = MINI_RES_X;
	dim[1] = MINI_RES_Y;
	fill_background(&g->minimap.img, dim, 0x404040);
	draw_map(g, 0);
	draw_player(g, g->player.x, g->player.y);
	mlx_put_image_to_window(g->data.mlx, g->data.win, g->minimap.img.img,
		RES_X - MINI_RES_X + 5, 0);
}
