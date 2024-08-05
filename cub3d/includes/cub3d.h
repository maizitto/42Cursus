/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:03:38 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 15:30:28 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BONUS 1

# include "includes.h"

//errors
void	quit(char *str, int flag);
int		ft_close_x(t_game *game);
void	reset_matrix(int **matrix);

//utils
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
int		skip_spaces(char *file);
void	print_matrix(char **matrix);
void	print_controls();
void	print_info(t_game *game);
unsigned long	get_time_in_mms(void);
void	draw_fps_counter(t_game *g);


//init
void	init_asset(t_asset *img);
void	init_rgb(t_rgb *rgb);
void	init_sprite(t_sprite *sprite);
void	init_wal_text(t_wal_text *w_text);
void	init_elements_struct(t_elements *elements);
void	init_elements(t_game *game);
void	init_player(t_player *player);
void	init_ray(t_ray *ray);
void	init_textures_pixels(t_game *game);
void	init_minimap_struct(t_minimap *minimap);
void	init_map(t_map *map);
void	init_struct(t_game *game);
void	init_mlx(t_game *game);
void	init_game(t_game *game, char *path_map);
void	init_engine(t_game *game);

//validator
bool	path_validator(char *path);
char	**store_file(char *path);
void	check_path(t_game *game, t_sprite *space);
void	parse_map(t_game *game);
bool	set_wall(t_game *game, int index);

//movement
void	forward_move(t_game *g);
void	back_move(t_game *g);
void	left_move(t_game *g);
void	right_move(t_game *g);
void	rotate(t_game *g, double rotdir);
void	input(t_game *g);
int		movs(t_game *g);

//game
int 	routine(t_game *game);
void	visual(t_game *game);
void	raycasting(t_game *game);
void	up_texture(t_data *d, t_wal_text *tex, t_ray *ray, int x);


#endif