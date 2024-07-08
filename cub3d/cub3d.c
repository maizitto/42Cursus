/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:25:22 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 11:49:28 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

static void	print_game(t_game *game)
{
	printf("North texture: %s\n", game->w_text.no);
	printf("South texture: %s\n", game->w_text.so);
	printf("West texture: %s\n", game->w_text.we);
	printf("East texture: %s\n", game->w_text.ea);
	printf("Floor color: %d, %d, %d\n", game->w_text.f_rgb.r, game->w_text.f_rgb.g, game->w_text.f_rgb.b);
	printf("Ceiling color: %d, %d, %d\n", game->w_text.c_rgb.r, game->w_text.c_rgb.g, game->w_text.c_rgb.b);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		quit(START_ERR, 1);
	init_game(&game, argv[1]);
	print_matrix(game.file);
	print_game(&game);
}
