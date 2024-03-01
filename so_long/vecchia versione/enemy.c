/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:06:01 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/01 16:46:04 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//MULTI ENEMY
static void	aux_enemy(t_game *g, int x, t_tile *p)
{
	if (p[x].type == 48)
	{
		p[x].type = 49;
		if ((g->mat[p[x].posx + 1][p[x].posy] == 48
			&& g->mat[p[x].posx][p[x].posy + 1] == 48
			&& g->mat[p[x].posx + 1][p[x].posy + 1] != '1'
			&& g->mat[p[x].posx - 1][p[x].posy - 1] != '1' )
			|| (g->mat[p[x].posx - 1][p[x].posy] == 48
			&& g->mat[p[x].posx][p[x].posy - 1] == 48
			&& (g->mat[p[x].posx - 1][p[x].posy - 1] != '1')
			&& (g->mat[p[x].posx + 1][p[x].posy + 1] != '1')))
			g->mat[p[x].posx][p[x].posy] = 'X';
		g->npath++;
	}
}

void	enemy(t_game *g)
{
	int	x;

	srand(time(NULL));
	x = 1;
	while (g->aux_rand != g->npath)
	{
		x = rand() % g->aux_rand;
		aux_enemy(g, x, g->pos_path);
	}
	free (g->pos_path);
}
// SINGLE ENEMY 
/*
static int	aux_enemy(t_game *g, int flag, int x, t_tile *p)
{
	if (p[x].type == 48)
	{
		p[x].type = 49;
		if ((g->mat[p[x].posx + 1][p[x].posy] == 48
			&& g->mat[p[x].posx][p[x].posy + 1] == 48
			&& g->mat[p[x].posx + 1][p[x].posy + 1] != '1'
			&& g->mat[p[x].posx - 1][p[x].posy - 1] != '1' )
			|| (g->mat[p[x].posx - 1][p[x].posy] == 48
			&& g->mat[p[x].posx][p[x].posy - 1] == 48
			&& (g->mat[p[x].posx - 1][p[x].posy - 1] != '1')
			&& (g->mat[p[x].posx + 1][p[x].posy + 1] != '1')))
		{
			flag = 1;
			g->mat[p[x].posx][p[x].posy] = 'X';
		}
		g->npath++;
	}
	return (flag);
}

void	enemy(t_game *g)
{
	int	x;
	int	flag;

	srand(time(NULL));
	x = 1;
	flag = 0;
	while (!flag && g->aux_rand != g->npath)
	{
		x = rand() % g->aux_rand;
		flag = aux_enemy(g, flag, x, g->pos_path);
	}
	free (g->pos_path);
}
*/
