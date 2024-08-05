/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:25:22 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 15:46:22 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		quit(START_ERR, 1);
	init_game(&game, argv[1]);
	init_engine(&game);
	input(&game);
	// print_controls();
	// print_info(&game);
	mlx_loop_hook(game.data.mlx, routine, &game);
	mlx_loop(game.data.mlx);
}
