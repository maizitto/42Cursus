/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:21:10 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/07 19:24:05 by mmasitto         ###   ########.fr       */
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

typedef struct s_game
{
	t_map		map;
	t_data		data;
	t_asset		asset;
}				t_game;

#endif