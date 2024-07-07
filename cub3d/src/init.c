/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:30:30 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/07 20:08:25 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	path_validator(char *p)
{
	int	i;

	i = ft_strlen(p) - 1;
	if (p[i] != 'b' || p[i - 1] != 'u' || p[i - 2] != 'c' || p[i - 3] != '.')
		return (1);
	return (0);
}

void	init_game(t_game *game, char *str)
{
	game->map.map = NULL;
	game->map.rows = 0;
	game->map.cols = 0;
	game->data.mlx = NULL;
	game->data.win = NULL;
	game->asset.path = NULL;
	game->asset.img = NULL;
	game->asset.addr = NULL;
	game->asset.bpp = 0;
	game->asset.line_length = 0;
	game->asset.endian = 0;
	if (path_validator(str))
		quit(CUB_ERR, 1);
	game->map.path = ft_strdup(str);
	if (!game->map.path)
		quit(MALLOC_ERR, 1);
	if (parser(game))
		quit(DATA_ERR, 1);
}
