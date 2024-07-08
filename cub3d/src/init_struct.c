/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:30:30 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 11:40:33 by mmasitto         ###   ########.fr       */
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

static char	**aux_store_file(char *str, int fd, int i, char **file)
{
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(OPEN_ERR, 1);
	file = malloc(sizeof(char *) * (i + 1));
	if (!file)
		quit(MALLOC_ERR, 1);
	while (j < i)
	{
		line = get_next_line(fd);
		file[j] = ft_strdup(line);
		if (!file[j])
			quit(MALLOC_ERR, 1);
		j++;
	}
	file[j] = NULL;
	close(fd);
	return (file);
}

static char	**store_file(char *str)
{
	int		i;
	int		fd;
	char	**file;

	fd = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(OPEN_ERR, 1);
	while (get_next_line(fd) > 0)
		i++;
	close(fd);
	file = NULL;
	file = aux_store_file(str, 0, i, file);
	return (file);
}

static void	init_textures(t_game *game)
{
	game->w_text.no = NULL;
	game->w_text.so = NULL;
	game->w_text.ea = NULL;
	game->w_text.we = NULL;
	game->w_text.c_rgb.r = -1;
	game->w_text.c_rgb.g = -1;
	game->w_text.c_rgb.b = -1;
	game->w_text.c_rgb.set = 0;
	game->w_text.f_rgb.r = -1;
	game->w_text.f_rgb.g = -1;
	game->w_text.f_rgb.b = -1;
	game->w_text.f_rgb.set = 0;
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
	game->file = store_file(str);
	if (!game->file)
		quit(MALLOC_ERR, 1);
	init_textures(game);
	set_wall(game);
}
