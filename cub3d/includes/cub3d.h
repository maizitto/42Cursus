/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:03:38 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/09 00:36:50 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"

//init
void	init_game(t_game *game, char *str);
bool	set_wall(t_game *g, int i);

//utils
int		ft_atoi(const char *str);
int		skip_spaces(char *file);
void	print_matrix(char **matrix);

//errors
void	quit(char *str, int flag);

//parser
void	parse_map(t_game *game);
void	check_path(t_game *g);

#endif