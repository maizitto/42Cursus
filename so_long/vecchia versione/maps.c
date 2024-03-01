/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:32:04 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/01 15:36:07 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_name_map(char *path, t_game *game)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] == 'r' && path[len - 2] == 'e'
		&& path[len - 3] == 'b' && path[len - 4] == '.')
	{
		game->map.path = path;
		return (1);
	}
	else
	{
		return (ft_close("File extension not valid", 1, game));
	}
}

static int	set_dim_map(t_game *game, char *path)
{
	int		fd;
	char	*temp;
	int		x;

	check_name_map(path, game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_close("File's opening failed", 1, game));
	temp = get_next_line(fd);
	if (!temp[0] || !temp)
		return (ft_close("File Empty", 1, game));
	game->map.width = ft_strlen(temp) - 1;
	while (temp && ++game->map.height)
	{
		x = ft_strlen(temp);
		if (temp[x - 1] == '\n')
			x--;
		free(temp);
		if (x != game->map.width)
			return (ft_close("Maps not rectangular", 1, game));
		temp = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	valid_matrix(t_game *game, int i)
{
	int	j;
	int	nplayer;

	i = -1;
	nplayer = 0;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->mat[i][j] == 'P')
				nplayer++;
			else if (game->mat[i][j] == 48)
				game->npath++;
		}
	}
	if (nplayer != 1)
		ft_close("Too much player", 2, game);
	return (1);
}

static int	check_matrix(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->mat[i][j] != 49 && (j == 0 || i == 0
			|| j == game->map.width - 1 || i == game->map.height - 1))
				return (ft_close("Map's walls not valid", 2, game));
			else if (!check_tile(game->mat[i][j]))
				return (ft_close("Invalid chars on map", 2, game));
			else if (game->mat[i][j] == 'P')
				set_tile(game, 'P', i, j);
			else if (game->mat[i][j] == 'E')
				set_tile(game, 'E', i, j);
			else if (game->mat[i][j] == 'C')
				set_tile(game, 'C', i, j);
		}
	}
	valid_matrix(game, 0);
	check_path(game);
	return (1);
}

int	set_matrix(t_game *game, char *path)
{
	int		j;
	int		fd;
	char	*line;

	if (!set_dim_map(game, path))
		return (0);
	game->mat = (char **)malloc(sizeof(char *) * game->map.height);
	if (!game->mat)
		ft_close("Matrix Malloc Failed", 1, game);
	j = -1;
	fd = open(path, O_RDONLY);
	if (!fd)
		ft_close("Path not found", 2, game);
	line = get_next_line(fd);
	if (!line)
		ft_close("Get Next Line failed", 2, game);
	while (line)
	{
		line[game->map.width] = '\0';
		game->mat[++j] = line;
		line = get_next_line(fd);
	}
	return (check_matrix(game));
}
