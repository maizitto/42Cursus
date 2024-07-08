/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:41:40 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 11:46:29 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_rgb(t_rgb *rgb, char *str)
{
	if (rgb->set)
		quit(RGB_ERR, 1);
	rgb->r = ft_atoi(&str[2]);
	rgb->g = ft_atoi(&str[4]);
	rgb->b = ft_atoi(&str[6]);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255 
		|| rgb->b < 0 || rgb->b > 255)
		quit(RGB_ERR, 1);
	rgb->set = 1;
}

static void	set_textures(char **texture, char *str, int j)
{
	if (!*texture)
		*texture = ft_strdup(ft_substr(str, j, ft_strlen(str) - j));
	else
		quit(TEXTURE_ERR, 1);
}

void	set_wall(t_game *g)
{
	int	i;

	i = 0;
	while (g->file[i])
	{
		if (g->file[i][0] == 'N' && g->file[i][1] == 'O')
			set_textures(&g->w_text.no, g->file[i], 3);
		else if (g->file[i][0] == 'S' && g->file[i][1] == 'O')
			set_textures(&g->w_text.so, g->file[i], 3);
		else if (g->file[i][0] == 'W' && g->file[i][1] == 'E')
			set_textures(&g->w_text.we, g->file[i], 3);
		else if (g->file[i][0] == 'E' && g->file[i][1] == 'A')
			set_textures(&g->w_text.ea, g->file[i], 3);
		else if (g->file[i][0] == 'F')
			set_rgb(&g->w_text.f_rgb, g->file[i]);
		else if (g->file[i][0] == 'C')
			set_rgb(&g->w_text.c_rgb, g->file[i]);
		else if (g->file[i][0] == '1')
			break ;
		i++;
	}
}
