/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:25:22 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/04 12:00:07 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	print_controls(void)
{
	printf("\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░░█▀▀░█▀█░█▀█░▀█▀░█▀▄░█▀█░█░░░█▀▀\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░░█░░░█░█░█░█░░█░░█▀▄░█░█░█░░░▀▀█\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀\n");
	printf("\n");
	printf("\tW : move forward");
	printf("\tS : move backward\n");
	printf("\tA : strafe left\t");
	printf("\tD : strafe right\n");
	printf("\t< : rotate left\t");
	printf("\t> : rotate right\n");
	if (BONUS)
		printf("\t\tMouse : rotate view\n");
	printf("\n");
}

static void	print_info(t_game *game)
{
	printf("\nNorth texture: %s\n", game->w_text.no);
	printf("\nSouth texture: %s\n", game->w_text.so);
	printf("\nWest texture: %s\n", game->w_text.we);
	printf("\nEast texture: %s\n", game->w_text.ea);
	printf("\nFloor color: %d, %d, %d\n", game->w_text.f_rgb.r,
		game->w_text.f_rgb.g, game->w_text.f_rgb.b);
	printf("\nCeiling color: %d, %d, %d\n", game->w_text.c_rgb.b,
		game->w_text.c_rgb.g, game->w_text.c_rgb.r);
	printf("\nNumber of collectibles (C MAP): %d\n", game->elements.c_count);
	printf("\nNumber of doors (D MAP): %d\n", game->elements.d_count);
	printf("\nNumber of enemies (E MAP): %d\n", game->elements.e_count);
	printf("\nPlayer position: %f, %f\n", game->player.x, game->player.y);
	printf("\nMap:\n");
}

// static int	routine(t_game *g)
// {
// 	static unsigned long	last_frame_time;
// 	unsigned long			current_time;
// 	unsigned long			frame_time;

// 	last_frame_time = 0;
// 	current_time = get_time_in_mms();
// 	frame_time = current_time - last_frame_time;
// 	if (frame_time >= FPS_LIMIT)
// 	{
// 		g->frametime_sec = frame_time / 1000.0;
// 		g->player.move_speed = g->frametime_sec * MOVE_SPEED;
// 		g->player.rot_speed = g->frametime_sec * ROT_SPEED;
// 		// listener_input(g);
// 		visual(g);
// 		draw_fps_counter(g);
// 		last_frame_time = current_time;
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		quit(START_ERR, 1);
	init_game(&game, argv[1]);
	init_engine(&game);
	// listener_input(&game);
	print_controls();
	print_info(&game);
	// mlx_loop_hook(game.data.mlx, routine, &game);
	// mlx_loop(game.data.mlx);
}
