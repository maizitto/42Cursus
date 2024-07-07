/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:09:14 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/07 20:12:07 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "includes.h"
# include "get_next_line.h"

# define START_ERR "Invalid use of game -> Use example: ./cub3D map.cub"
# define CUB_ERR "Invalid file extension. '.cub' file needed\n"
# define ARG_ERR "Invalid number of arguments -> Use example: ./cub3D map.cub"
# define OPEN_ERR "opening the map file"
# define DATA_ERR "bad textures data in the file"
# define MALLOC_ERR "malloc error"
# define MAP_ERR "map error"
# define MLX_ERR "mlx initialization error"
# define IMG_ERR "image initialization error"
# define MALLOC_ERR "malloc error"
# define GNL_ERR "get_next_line error"

void		quit(char *str, int flag);

#endif