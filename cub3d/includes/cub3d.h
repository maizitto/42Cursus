/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:03:38 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/08 11:46:05 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"

//init
void	init_game(t_game *game, char *str);
void	set_wall(t_game *g);

//utils
int		ft_atoi(const char *str);

//errors
void	quit(char *str, int flag);
#endif