/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/09 10:33:58 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_rgb(t_game *g, t_rgb *rgb, char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	if (rgb->set == 1)
		quit(g, RGB_ERR, 1);
	while (str[++i] < '0' || str[i] > '9')
	{
		if (str[i] == '\0')
			quit(g, RGB_ERR, 1);
	}
	tmp = ft_split(&str[i], ',');
	if (!tmp[0] || !tmp[1] || !tmp[2] || tmp[3])
		quit(g, RGB_ERR, 1);
	rgb->r = ft_atoi(tmp[0]);
	rgb->g = ft_atoi(tmp[1]);
	rgb->b = ft_atoi(tmp[2]);
	free_matrix((void **)tmp, 4);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255
		|| rgb->b < 0 || rgb->b > 255)
		quit(g, RGB_ERR, 1);
	rgb->set = 1;
}

static void	set_textures(char **texture, char *str, int j, t_game *game)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new_texture;

	while (str[j] == ' ')
		j++;
	start = j;
	end = ft_strlen(str);
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\n'))
		end--;
	len = end - start;
	new_texture = (char *)malloc(len + 1);
	if (!new_texture)
		quit(game, MALLOC_ERR, 1);
	if (*texture)
		free(*texture);
	ft_strlcpy(new_texture, &str[start], len + 1);
	*texture = new_texture;
}

static bool	validate_wall(t_game *game)
{
	if (!game->w_text.no || !game->w_text.so || !game->w_text.we
		|| !game->w_text.ea || !game->w_text.f_rgb.set
		|| !game->w_text.c_rgb.set)
		return (1);
	parse_map(game);
	return (0);
}

static char	**extract_map(t_game *g, char **map, int i, int j)
{
	while (g->file[++i])
	{
		while (g->file[i][j] == ' ')
			j++;
		if (g->file[i][j] == '1')
			break ;
	}
	j = i;
	while (g->file[j])
		j++;
	g->temp = j - i;
	map = ft_calloc(sizeof(char *), ((j - i) + 1));
	if (!map)
		quit(g, MALLOC_ERR, 1);
	j = -1;
	while (++j < g->temp)
	{
		map[j] = ft_strdup(g->file[i]);
		i++;
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
			set_rgb(g, &g->w_text.f_rgb, g->file[i]);
		else if (g->file[i][j] == 'C')
			set_rgb(g, &g->w_text.c_rgb, g->file[i]);
		else if (g->file[i][j] == '1')
			break ;
		i++;
	}
	g->map.map = extract_map(g, g->map.map, -1, 0);
	if (validate_wall(g))
		quit(g, DATA_ERR, 1);
	return (0);
}
