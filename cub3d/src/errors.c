/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/05 15:33:18 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"

static void	ft_error(char *str)
{
	int	x;

	x = write(1, "Error\n", 6);
	x = write(1, str, ft_strlen(str));
	(void)x;
	exit(0);
}

void	quit(char *str, int flag)
{
	if (flag != 0)
		ft_error(str);
	if (flag == 1)
		exit(0);
}

int	ft_close_x(t_game *game)
{
	(void)game;
	quit("Bye Bye", 0);
	return (0);
}

void	reset_matrix(int **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i < RES_Y)
	{
		j = -1;
		while (++j < RES_X)
		{
			matrix[i][j] = 0;
		}
	}
}
