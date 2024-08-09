/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:28:53 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 11:03:33 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_raycast(int x, t_ray *ray, t_game *g)
{
	init_ray(ray);
	ray->cam_x = 2 * x / (double)RES_X - 1;
	ray->dir_x = g->player.dir_x + g->player.plane_x * ray->cam_x;
	ray->dir_y = g->player.dir_y + g->player.plane_y * ray->cam_x;
	ray->map_x = (int)g->player.x;
	ray->map_y = (int)g->player.y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->side = 0;
}

static void	dda_init(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_y;
	}
}

static void	dda_exec(t_game *g, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
		if (g->map.map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	calculate_line(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_x - ray->delta_x);
	else
		ray->wall_dist = (ray->side_y - ray->delta_y);
	ray->line_height = (int)(RES_Y / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + RES_Y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_end >= RES_Y)
		ray->draw_end = RES_Y - 1;
	if (ray->side == 0)
		ray->wall_x = g->player.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = g->player.x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycasting(t_game *g)
{
	int		x;

	x = -1;
	while (++x < RES_X)
	{
		init_raycast(x, &g->ray, g);
		dda_init(g, &g->ray);
		dda_exec(g, &g->ray);
		calculate_line(g, &g->ray);
		up_texture(&g->data, &g->w_text, &g->ray, x);
	}
}
