/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:41:40 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/07 20:00:16 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_map(t_game *game, int fd);

int	parser(t_game *game)
{
	int	fd;

	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (parse_map(game, fd))
		return (1);
	close(fd);
	return (0);
}

static int	parse_map(t_game *game, int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(fd);
		ret = ft_strlen(line);
		if (ret < 0)
			return (1);
		if (ret == 0)
			break ;
		printf("%s\n", line);
		free(line);
	}
	return (0);
	(void)game;
}

