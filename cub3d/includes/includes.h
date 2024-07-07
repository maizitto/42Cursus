/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:04:35 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/07 20:12:06 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <time.h>
# include <stdint.h>

# include "errors.h"
# include "get_next_line.h"
# include "structures.h"

//map size
# define RES_X 1440
# define RES_Y 810

# define MINI_RES_X 288
# define MINI_RES_Y 162

//keycodes
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125



#endif