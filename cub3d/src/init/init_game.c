/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:41:40 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 12:42:05 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_texture_game(t_game *g, t_asset *image, char *path)
{
	init_asset(image);
	image->img = mlx_xpm_file_to_image(g->data.mlx, path, &g->w_text.size,
			&g->w_text.size);
	if (image->img == NULL)
		quit(TEXTURE_ERR, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bpp,
			&image->bpp, &image->endian);
	return ;
}

static int	*xti(t_game *g, char *path)
{
	t_asset	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_game(g, &tmp, path);
	buffer = (int *)ft_calloc(1,
			sizeof(buffer) * (g->w_text.size * g->w_text.size));
	if (!buffer)
		quit(MALLOC_ERR, 1);
	y = -1;
	while (++y < g->w_text.size)
	{
		x = -1;
		while (++x < g->w_text.size)
			buffer[y * g->w_text.size + x] = tmp.addr[y * g->w_text.size + x];
	}
	mlx_destroy_image(g->data.mlx, tmp.img);
	return (buffer);
}

static void	init_textures_pixels(t_game *g)
{
	int	i;

	i = -1;
	g->data.texture_pixels = ft_calloc(RES_Y + 1, sizeof(int *));
	if (!g->data.texture_pixels)
		quit(MALLOC_ERR, 1);
	while (++i < RES_Y)
	{
		g->data.texture_pixels[i] = ft_calloc(RES_X + 1, sizeof(int));
		if (!g->data.texture_pixels[i])
			quit(MALLOC_ERR, 1);
	}
}

void	init_mlx(t_game *g)
{
	g->data.mlx = mlx_init();
	if (!g->data.mlx)
		quit(MLX_ERR, 1);
	g->data.win = mlx_new_window(g->data.mlx, RES_X, RES_Y, "Cub3D");
	if (!g->data.win)
		quit(MLX_ERR, 1);
	//mlx_mouse_move(g->data.mlx, g->data.win, RES_Y / 2, RES_X / 2);
	g->data.textures = (int **)ft_calloc(5, sizeof * g->data.textures);
	if (!g->data.textures)
		quit(MALLOC_ERR, 1);
	g->data.textures[0] = xti(g, g->w_text.no);
	g->data.textures[1] = xti(g, g->w_text.so);
	g->data.textures[2] = xti(g, g->w_text.we);
	g->data.textures[3] = xti(g, g->w_text.ea);
	init_textures_pixels(g);
	return ;
}

void	init_game(t_game *game, char *path_map)
{
	init_struct(game);
	if (path_validator(path_map))
		quit(CUB_ERR, 1);
	game->map.path = ft_strdup(path_map);
	if (!game->map.path)
		quit(MALLOC_ERR, 1);
	game->file = store_file(path_map);
	if (!game->file)
		quit(MALLOC_ERR, 1);
	if (set_wall(game, 0))
		quit(DATA_ERR, 1);
}
