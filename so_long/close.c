/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:12:57 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/07 10:45:31 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_matrix(char **ptr, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.height)
		free(ptr[i]);
	free(ptr);
}

void	ft_destroy(t_game *game)
{
	int	i;

	i = -1;
	if (game->map.bg.image.img)
		mlx_destroy_image(game->mlx, game->map.bg.image.img);
	if (game->map.player.image.img)
		mlx_destroy_image(game->mlx, game->map.player.image.img);
	if (game->map.wall.image.img)
		mlx_destroy_image(game->mlx, game->map.wall.image.img);
	if (game->map.coin[0].image.img)
		mlx_destroy_image(game->mlx, game->map.coin[0].image.img);
	if (game->map.enemy.image.img)
		mlx_destroy_image(game->mlx, game->map.enemy.image.img);
	if (game->map.exit[0].image.img)
		mlx_destroy_image(game->mlx, game->map.exit[0].image.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	while (++i < 5)
		free(game->star[i]);
}

int	ft_close(char *s, int type, t_game *game)
{
	if (type == 1)
		ft_printf("Error\nDetails: %s\n", s);
	else if (type == 2)
	{
		clean_matrix(game->mat, game);
		ft_printf("Error\nDetails: %s\n", s);
	}
	else if (type == 0 || type == 9)
	{
		clean_matrix(game->mat, game);
		ft_destroy(game);
		if (type == 0)
		{
			ft_printf("Bye\n");
		}
		else
			ft_printf("You are such a LOSER\n%s\n", s);
	}
	exit (1);
}

int	ft_xclose(t_game *game)
{
	ft_close("Game closed in a clean way", 9, game);
	return (0);
}
