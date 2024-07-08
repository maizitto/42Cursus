/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:21:10 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 11:36:07 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map
{
	char	*path;
	char	**map;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_asset
{
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_asset;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	set;
}	t_rgb;

typedef struct s_w_text
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	t_rgb	c_rgb;
	t_rgb	f_rgb;
}	t_wal_text;

typedef struct s_game
{
	t_map		map;
	t_data		data;
	t_asset		asset;
	char		**file;
	t_wal_text	w_text;
}				t_game;

#endif