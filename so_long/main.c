/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:43:26 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/30 11:45:31 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.height)
		ft_printf("%s\n", game->mat[i]);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
	{
		ft_printf("Param's number invalid\n");
		return (1);
	}
	else
	{
		set_game(&game);
		if (set_matrix(&game, argv[1]))
		{
			enemy(&game);
			game_init(&game);
		}
	}
}
