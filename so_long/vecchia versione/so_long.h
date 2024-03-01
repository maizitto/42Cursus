/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:25:34 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/05 13:52:11 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdint.h>
# include <time.h>
# include "minilibx_mms_20200219/mlx.h"

# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "structures.h"

//MAPS
int		set_matrix(t_game *game, char *path);
char	**dup_matrix(t_game *game);
void	print_matrix(t_game *game);
//GAME
int		set_game(t_game *game);
int		game_init(t_game *game);
int		draw_map(t_game *game);
int		loop(t_game *game);
void	loop_coin(t_game *game);
//CLOSE
int		ft_close(char *str_err, int type, t_game *game);
void	clean_matrix(char **ptr, t_game *game);
int		ft_xclose(t_game *game);
void	ft_destroy(t_game *game);
//VAR
int		check_tile(char c);
void	set_tile(t_game *game, char type, int posx, int posy);
void	check_path(t_game *game);
int		image_load(t_game *game);
int		img_win(t_game *game, void *img, int x, int y);
int		input_key(int key, t_game *game);
int		move_pg(t_game *game, int x, int y, int move);
void	enemy(t_game *g);
void	init_coin(t_game *game);
void	dec_coin(t_game *game, int x, int y);

#endif