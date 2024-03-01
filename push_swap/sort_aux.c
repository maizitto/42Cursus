/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:23:13 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:58:56 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//restituisce la metà della lunghezza passata come parametro
int	half(int length)
{
	int	ret;

	if (length % 2 == 0)
		ret = length / 2;
	else
		ret = length / 2 + 1;
	return (ret);
}

//verifica il costo computazionale del passaggio dell'elemento temp
//nello stack_a o nello stack_b
void	count_mv(t_stack *s, char type)
{
	s->half_a = half(s->lenght_a);
	s->half_b = half(s->lenght_b);
	if (s->i_temp_a < s->half_a && s->i_temp_b < s->half_b)
	{
		if (s->i_temp_a < s->i_temp_b)
			s->t_mov = s->i_temp_b;
		else
			s->t_mov = s->i_temp_a;
	}
	else if (s->i_temp_a >= s->half_a && s->i_temp_b >= s->half_b)
	{
		if ((s->lenght_a - s->i_temp_a) > (s->lenght_b - s->i_temp_b))
			s->t_mov = s->lenght_a - s->i_temp_a;
		else
			s->t_mov = s->lenght_b - s->i_temp_b;
	}
	else
	{
		if (s->i_temp_a < s->half_a && s->i_temp_b >= s->half_b)
			s->t_mov = s->i_temp_a + (s->lenght_b - s->i_temp_b);
		else
			s->t_mov = s->i_temp_b + (s->lenght_a - s->i_temp_a);
	}
	aux_moves(s, type);
}

//setta il valore con costo computazionale minore 
//come elemento da spostare nello stack_a o stack_b
void	aux_moves(t_stack *s, char type)
{
	if (type == 'b')
	{
		if (s->i_temp_a == 0 || s->t_mov < s->n_mov)
		{
			s->i_a = s->i_temp_a;
			s->i_b = s->i_temp_b;
			s->n_mov = s->t_mov;
		}
	}
	if (type == 'a')
	{
		if (s->i_temp_b == 0 || s->t_mov < s->n_mov)
		{
			s->i_a = s->i_temp_a;
			s->i_b = s->i_temp_b;
			s->n_mov = s->t_mov;
		}
	}
}

//Funzione finale che ruota lo stack_a per portare il numero minore in cima
void	final(t_stack *s)
{
	int	i;

	i = -1;
	get_maxmin(s);
	if (s->min_a.pos < s->lenght_a / 2)
		while (++i < s->min_a.pos)
			ra(s);
	else
		while (++i < s->lenght_a - s->min_a.pos)
			rra(s);
}
