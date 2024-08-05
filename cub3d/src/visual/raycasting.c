/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:28:53 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/02 18:15:35 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_line(t_game *g, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < RES_Y)
	{
		if (y < ray->draw_start)
			g->data.texture_pixels[y][x] = g->map.c_color;
		else if (y >= ray->draw_start && y <= ray->draw_end)
			g->data.texture_pixels[y][x] = g->map.f_color;
		else
			g->data.texture_pixels[y][x] = 0;
		y++;
	}
}

static void	dda(t_game *g, t_ray *ray)
{
	while (ray->side == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (g->map.map[ray->map_x][ray->map_y] == '1')
			ray->side = 1;
	}
}

static void	calc_dist(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - g->player.x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->wall_dist = (ray->map_y - g->player.y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
}

static void	calc_line(t_ray *ray)
{
	ray->line_height = (int)(RES_Y / ray->wall_dist);
	ray->draw_start = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_end >= RES_Y)
		ray->draw_end = RES_Y - 1;
}

void	raycasting(t_game *g)
{
	int		x;

	x = 0;
	while (x < RES_X)
	{
		init_ray(&g->ray);
		dda(g, &g->ray);
		calc_dist(g, &g->ray);
		calc_line(&g->ray);
		draw_line(g, &g->ray, x);
		x++;
	}
}
