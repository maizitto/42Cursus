/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 17:48:26 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/errors.h"

void	free_matrix(void **matrix, int end)
{
	int	i;

	i = 0;
	(void)end;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	free_textures(t_game *game)
{
	if (game->w_text.no)
		free(game->w_text.no);
	if (game->w_text.so)
		free(game->w_text.so);
	if (game->w_text.we)
		free(game->w_text.we);
	if (game->w_text.ea)
		free(game->w_text.ea);
	free_matrix((void **)game->data.textures, 5);
	if (game->data.texture_pixels)
		free_matrix((void **)game->data.texture_pixels, 0);
}

static void	free_asset(t_asset *asset, void *mlx)
{
	if (asset->path)
		free(asset->path);
	if (asset->img)
		mlx_destroy_image(mlx, asset->img);
}

static void	free_elements(t_game *game)
{
	if (game->elements.collectibles)
		free(game->elements.collectibles);
	if (game->elements.doors)
		free(game->elements.doors);
	if (game->elements.enemies)
		free(game->elements.enemies);
}

void	free_game(t_game *game)
{
	if (game->map.map)
	{
		free_matrix((void **)game->map.map, game->map.rows);
	}
	if (game->data.textures)
		free_textures(game);
	if (game->frame.img)
		free_asset(&game->frame, (void *)game->data.mlx);
	if (game->minimap.img.img)
		free_asset(&game->minimap.img, (void *)game->data.mlx);
	if (game->fps.img)
		free_asset(&game->fps, (void *)game->data.mlx);
	free_elements(game);
	return ;
}
