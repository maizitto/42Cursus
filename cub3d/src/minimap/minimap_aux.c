/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:43 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 11:25:47 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_map(t_game *g, int y)
{
	double	map[2];
	int		x;

	y = -1;
	while (++y < g->map.rows)
	{
		x = -1;
		while (++x < g->map.cols)
		{
			map[0] = x * g->minimap.cell_w;
			map[1] = y * g->minimap.cell_h;
			if (g->map.map[y][x] == '1')
				draw_wall(g, map, g->minimap.cell_w - 1,
					g->minimap.cell_h - 1);
		}
	}
}

void	pixel_to_screen(t_asset *data, int *cord, int color)
{
	int	*dst;
	int	x;
	int	y;

	x = cord[0];
	y = cord[1];
	if (x >= 0 && x < MINI_RES_X && y >= 0 && y < MINI_RES_Y)
	{
		dst = data->addr + (y * (data->line_length / sizeof(int))) + x;
		*dst = color;
	}
}

void	fill_background(t_asset *data, int *dim, int bg_color)
{
	int	width;
	int	height;
	int	x_y[2];

	width = dim[0];
	height = dim[1];
	x_y[1] = -1;
	while (++x_y[1] < height)
	{
		x_y[0] = -1;
		while (++x_y[0] < width)
		{
			pixel_to_screen(data, x_y, bg_color);
		}
	}
}

void	draw_wall(t_game *g, double *start,
	double size_x, double size_y)
{
	int	x;
	int	y;
	int	dim[2];

	x = (int)start[0];
	while (x < start[0] + size_x)
	{
		y = (int)start[1];
		while (y < start[1] + size_y)
		{
			dim[0] = x;
			dim[1] = y;
			pixel_to_screen(&g->minimap.img, dim, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void	draw_circle(t_asset *img_data, double *aux, int color)
{
	double	x;
	double	y;
	double	radius;
	int		dim[2];

	radius = aux[2];
	x = aux[0] - radius;
	while (x <= aux[0] + radius)
	{
		y = aux[1] - radius;
		while (y <= aux[1] + radius)
		{
			dim[0] = (int)x;
			dim[1] = (int)y;
			if ((x - aux[0]) * (x - aux[0])
				+ (y - aux[1]) * (y - aux[1]) <= radius * radius)
				pixel_to_screen(img_data, dim, color);
			y++;
		}
		x++;
	}
}
