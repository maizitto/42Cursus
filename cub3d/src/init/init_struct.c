/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:30:30 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 14:21:54 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_asset(t_asset *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->path = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	init_rgb(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	rgb->set = 0;
}

void	init_sprite(t_sprite *sprite)
{
	sprite->x = 0.0;
	sprite->y = 0.0;
	sprite->type = '0';
}

void	init_wal_text(t_wal_text *w_text)
{
	w_text->no = NULL;
	w_text->so = NULL;
	w_text->ea = NULL;
	w_text->we = NULL;
	init_rgb(&w_text->c_rgb);
	init_rgb(&w_text->f_rgb);
	w_text->size = 0;
	w_text->index = 0;
	w_text->step = 0.0;
	w_text->pos = 0.0;
	w_text->x = 0;
	w_text->y = 0;
}

void	init_elements_struct(t_elements *elements)
{
	elements->collectibles = NULL;
	elements->c_count = 0;
	elements->doors = NULL;
	elements->d_count = 0;
	elements->enemies = NULL;
	elements->e_count = 0;
}
