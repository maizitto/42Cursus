/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:45:00 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/07 17:46:03 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_controls(void)
{
	printf("\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░░█▀▀░█▀█░█▀█░▀█▀░█▀▄░█▀█░█░░░█▀▀\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░░█░░░█░█░█░█░░█░░█▀▄░█░█░█░░░▀▀█\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀\n");
	printf("\n");
	printf("\tW : move forward");
	printf("\tS : move backward\n");
	printf("\tA : strafe left\t");
	printf("\tD : strafe right\n");
	printf("\t< : rotate left\t");
	printf("\t> : rotate right\n");
	if (BONUS)
		printf("\t\tMouse : rotate view\n");
	printf("\n");
}

void	print_info(t_game *game)
{
	printf("\nNorth texture: %s\n", game->w_text.no);
	printf("\nSouth texture: %s\n", game->w_text.so);
	printf("\nWest texture: %s\n", game->w_text.we);
	printf("\nEast texture: %s\n", game->w_text.ea);
	printf("\nFloor color: %d, %d, %d\n", game->w_text.f_rgb.r,
		game->w_text.f_rgb.g, game->w_text.f_rgb.b);
	printf("\nCeiling color: %d, %d, %d\n", game->w_text.c_rgb.b,
		game->w_text.c_rgb.g, game->w_text.c_rgb.r);
	printf("\nNumber of collectibles (C MAP): %d\n", game->elements.c_count);
	printf("\nNumber of doors (D MAP): %d\n", game->elements.d_count);
	printf("\nNumber of enemies (E MAP): %d\n", game->elements.e_count);
	printf("\nPlayer position: %f, %f\n", game->player.x, game->player.y);
	printf("\nMap:\n");
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
