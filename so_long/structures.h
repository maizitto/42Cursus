/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:23:24 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/05 13:44:01 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_image
{
	void	*img;
	int		heigh;
	int		width;
}				t_image;

typedef struct s_tile
{
	char	type;
	int		posx;
	int		posy;
	t_image	image;
}				t_tile;

typedef struct s_map
{
	char	*path;
	int		height;
	int		width;
	t_tile	player;
	t_tile	exit[10];
	int		nexit;
	int		ncoin;
	int		coin_coll;
	int		movcoin;
	t_tile	coin[10];
	t_tile	enemy;
	t_tile	wall;
	t_tile	bg;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	char	**mat;
	int		w;
	int		h;
	int		nmove;
	int		loop;
	int		npath;
	int		aux_rand;
	char	**star;
	t_tile	*pos_path;
}				t_game;

#endif