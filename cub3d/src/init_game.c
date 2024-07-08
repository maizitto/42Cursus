/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:41:40 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 17:34:01 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_rgb(t_rgb *rgb, char *str)
{
	if (rgb->set == 1)
		quit(RGB_ERR, 1);
	rgb->r = ft_atoi(&str[2]);
	rgb->g = ft_atoi(&str[4]);
	rgb->b = ft_atoi(&str[6]);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255 
		|| rgb->b < 0 || rgb->b > 255)
		quit(RGB_ERR, 1);
	rgb->set = 1;
}

static void	set_textures(char **texture, char *str, int j, t_game *game)
{
	if (*texture)
		quit(TEXTURE_ERR, 1);
	if (game->map.map)
		quit(MAP_ERR, 1);
	if (!*texture)
	{
		while (str[j] == ' ')
			j++;
		*texture = ft_strdup(ft_substr(str, j, ft_strlen(str) - j));
	}
	else
		quit(TEXTURE_ERR, 1);
}

bool	validate_wall(t_game *game)
{
	// printf("North texture: %s\n", game->w_text.no);
	// printf("South texture: %s\n", game->w_text.so);
	// printf("West texture: %s\n", game->w_text.we);
	// printf("East texture: %s\n", game->w_text.ea);
	// printf("Floor color: %d, %d, %d\n", game->w_text.f_rgb.r, game->w_text.f_rgb.g, game->w_text.f_rgb.b);
	// printf("Ceiling color: %d, %d, %d\n", game->w_text.c_rgb.r, game->w_text.c_rgb.g, game->w_text.c_rgb.b);
	if (!game->w_text.no || !game->w_text.so || !game->w_text.we
		|| !game->w_text.ea || !game->w_text.f_rgb.set
		|| !game->w_text.c_rgb.set)
		return (1);
	parse_map(game);
	return (0);
}

static char	**extract_map(t_game *g, char **map, int j, int i)
{
	i = -1;
	while (g->file[++i])
	{
		j = 0;
		while (g->file[i][j] == ' ')
			j++;
		if (g->file[i][j] == '1')
			break ;
	}
	j = i;
	while (g->file[j])
		j++;
	map = malloc(sizeof(char *) * (j - i + 1));
	if (!map)
		quit(MALLOC_ERR, 1);
	j = -1;
	while (g->file[i])
	{
		map[++j] = ft_strdup(g->file[i++]);
		if ((int)ft_strlen(map[j]) > g->map.cols)
			g->map.cols = ft_strlen(map[j]);
	}
	g->map.rows = j;
	return (map);
}

bool	set_wall(t_game *g, int i)
{
	int	j;

	while (g->file[i])
	{
		j = skip_spaces(g->file[i]);
		if (g->file[i][j] == 'N' && g->file[i][j + 1] == 'O')
			set_textures(&g->w_text.no, g->file[i], j + 2, g);
		else if (g->file[i][j] == 'S' && g->file[i][j + 1] == 'O')
			set_textures(&g->w_text.so, g->file[i], j + 2, g);
		else if (g->file[i][j] == 'W' && g->file[i][j + 1] == 'E')
			set_textures(&g->w_text.we, g->file[i], j + 2, g);
		else if (g->file[i][j] == 'E' && g->file[i][j + 1] == 'A')
			set_textures(&g->w_text.ea, g->file[i], j + 2, g);
		else if (g->file[i][j] == 'F')
			set_rgb(&g->w_text.f_rgb, g->file[i]);
		else if (g->file[i][j] == 'C')
			set_rgb(&g->w_text.c_rgb, g->file[i]);
		else if (g->file[i][j] == '1')
			break ;
		i++;
	}
	g->map.map = extract_map(g, g->map.map, 0, 0);
	if (validate_wall(g))
		quit(DATA_ERR, 1);
	return (0);
}
