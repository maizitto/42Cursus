/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 11:01:35 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	routine(t_game *g)
{
	unsigned long			current_time;
	unsigned long			frame_time;

	current_time = get_time_in_mms();
	frame_time = current_time - *(g->last_frame_time);
	if (frame_time >= FPS_LIMIT)
	{
		g->frametime_sec = frame_time / 1000.0;
		movs(g);
		visual(g);
		if (BONUS)
			draw_fps_counter(g);
		*g->last_frame_time = current_time;
	}
	return (0);
}

static void	set_color(t_asset *asset, int x, int y, int color)
{
	int	pixel;

	pixel = y * (asset->line_length / 4) + x;
	asset->addr[pixel] = color;
}

static void	pixel_color(t_game *g, t_asset *asset, int x, int y)
{
	if (g->data.texture_pixels[y][x] > 0)
		set_color(asset, x, y, g->data.texture_pixels[y][x]);
	else if (y < RES_Y / 2)
		set_color(asset, x, y, g->map.c_color);
	else if (y < RES_Y - 1)
		set_color(asset, x, y, g->map.f_color);
}

static void	draw(t_game *g)
{
	int		x;
	int		y;
	t_asset	frame;

	y = 0;
	init_asset(&frame);
	init_img_details(g, &frame, RES_X, RES_Y);
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			pixel_color(g, &frame, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->data.mlx, g->data.win, frame.img, 0, 0);
	mlx_destroy_image(g->data.mlx, frame.img);
}

void	visual(t_game *g)
{
	reset_matrix(g->data.texture_pixels);
	init_ray(&g->ray);
	raycasting(g);
	draw(g);
	if (BONUS)
		draw_minimap(g);
}
