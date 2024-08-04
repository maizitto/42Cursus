/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:41:40 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/04 12:16:32 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	aux_init_player_mov(t_game *g)
{
	if (g->player.dir == 'W')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
		g->player.plane_x = -0.66;
		g->player.plane_y = 0;
	}
	else if (g->player.dir == 'E')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
		g->player.plane_x = 0.66;
		g->player.plane_y = 0;
	}
}

static void	init_player_mov(t_game *g)
{
	if (g->player.dir == 'N')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = 0.66;
	}
	else if (g->player.dir == 'S')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = -0.66;
	}
	else
		aux_init_player_mov(g);
}

static void	init_img_details(t_game *g, t_asset *img, int width, int height)
{
	init_asset(img);
	img->img = mlx_new_image(g->data.mlx, width, height);
	if (!img->img)
		quit(MLX_ERR, 1);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}

//primo init_img_details per fps a schermo

void	init_engine(t_game *g)
{
	init_mlx(g);
	init_player_mov(g);
	init_img_details(g, &g->fps, 100, 100);
	// if (BONUS)
	// 	init_minimap(g);
	init_img_details(g, &g->frame, RES_X, RES_Y);
}
