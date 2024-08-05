/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:28:53 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 13:24:03 by mmasitto         ###   ########.fr       */
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
		if (ray->map_x >= 0 && ray->map_x < g->map.cols
			&& ray->map_y >= 0 && ray->map_y < g->map.rows)
		{
			if (g->map.map[ray->map_x][ray->map_y] == '1')
				ray->side = 1;
		}
	}
}

static void	calculate_line(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - g->player.x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->wall_dist = (ray->map_y - g->player.y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_height = (int)(RES_Y / ray->wall_dist);
	ray->draw_start = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + RES_Y / 2;
	if (ray->draw_end >= RES_Y)
		ray->draw_end = RES_Y - 1;
}

static void	get_texture_index(t_wal_text *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->index = WEST;
		else
			data->index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->index = SOUTH;
		else
			data->index = NORTH;
	}
}

void	up_texture(t_data *d, t_wal_text *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(tex, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - RES_Y / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = d->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			d->texture_pixels[y][x] = color;
		y++;
	}
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
