/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 15:48:01 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	routine(t_game *g)
{
	static unsigned long	last_frame_time;
	unsigned long			current_time;
	unsigned long			frame_time;

	last_frame_time = 0;
	current_time = get_time_in_mms();
	frame_time = current_time - last_frame_time;
	if (frame_time >= FPS_LIMIT)
	{
		g->frametime_sec = frame_time / 1000.0;
		g->player.move_speed = g->frametime_sec * MOVE_SPEED;
		g->player.rot_speed = g->frametime_sec * ROT_SPEED;
		input(g);
		visual(g);
		draw_fps_counter(g);
		last_frame_time = current_time;
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

static void	draw(t_game *g, t_asset *asset)
{
	int	x;
	int	y;

	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			pixel_color(g, asset, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->data.mlx, g->data.win, asset->img, 0, 0);
	// mlx_destroy_image(g->data.mlx, asset->img);
}

void	visual(t_game *g)
{
	reset_matrix(g->data.texture_pixels);
	init_ray(&g->ray);
	raycasting(g);
	draw(g, &g->frame);
	//draw_minimap(g);
}
