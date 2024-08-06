/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:30:30 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/06 10:17:57 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->dir = '0';
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_ray(t_ray *ray)
{
	ray->cam_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_minimap_struct(t_minimap *minimap)
{
	init_asset(&minimap->img);
	minimap->width = 0;
	minimap->height = 0;
	minimap->cell_w = 0;
	minimap->cell_h = 0;
}

void	init_map(t_map *map)
{
	map->path = NULL;
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->map_x = 0;
	map->map_y = 0;
	map->c_color = 0;
	map->f_color = 0;
}

void	init_struct(t_game *game)
{
	init_map(&game->map);
	game->data.mlx = NULL;
	game->data.win = NULL;
	game->data.textures = NULL;
	game->data.texture_pixels = NULL;
	init_minimap_struct(&game->minimap);
	init_asset(&game->fps);
	init_asset(&game->frame);
	init_player(&game->player);
	init_elements_struct(&game->elements);
	game->file = NULL;
	init_wal_text(&game->w_text);
	init_ray(&game->ray);
	game->frametime_sec = 0;
}
