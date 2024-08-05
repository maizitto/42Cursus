/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:21:10 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 17:44:29 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_asset
{
	char					*path;
	void					*img;
	int						*addr;
	int						bpp;
	int						line_length;
	int						endian;
}				t_asset;

typedef struct s_rgb
{
	int						r;
	int						g;
	int						b;
	int						set;
}	t_rgb;

typedef struct s_sprite
{
	double					x;
	double					y;
	char					type;
}	t_sprite;

typedef struct s_w_text
{
	char					*no;
	char					*so;
	char					*ea;
	char					*we;
	t_rgb					c_rgb;
	t_rgb					f_rgb;
	int						size;
	int						index;
	double					step;
	double					pos;
	int						x;
	int						y;
}	t_wal_text;

typedef struct s_elements
{
	t_sprite				*collectibles;
	int						c_count;
	t_sprite				*doors;
	int						d_count;
	t_sprite				*enemies;
	int						e_count;
}	t_elements;

typedef struct s_player
{
	char					dir;
	double					x;
	double					y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	int						moved;
	int						move_x;
	int						move_y;
	int						move_speed;
	int						rot_speed;
	int						rotate;
	int						keys[256];

}	t_player;

typedef struct s_ray
{
	double					cam_x;
	double					dir_x;
	double					dir_y;
	int						map_x;
	int						map_y;
	int						step_x;
	int						step_y;
	double					side_x;
	double					side_y;
	double					delta_x;
	double					delta_y;
	double					wall_dist;
	double					wall_x;
	int						side;
	int						line_height;
	int						draw_start;
	int						draw_end;
}	t_ray;

typedef struct s_mininmap
{
	t_asset					img;
	int						width;
	int						height;
	double					cell_w;
	double					cell_h;
}				t_minimap;

typedef struct s_map
{
	char					*path;
	char					**map;
	int						rows;
	int						cols;
	int						map_x;
	int						map_y;
	int						c_color;
	int						f_color;
}				t_map;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	int						**texture_pixels;
	int						**textures;
}				t_data;

typedef struct s_game
{
	t_map					map;
	t_data					data;
	t_minimap				minimap;
	t_asset					fps;
	t_asset					frame;
	t_player				player;
	t_elements				elements;
	char					**file;
	t_wal_text				w_text;
	t_ray					ray;
	double					frametime_sec;
}				t_game;

static unsigned long	last_frame_time;
 
#endif