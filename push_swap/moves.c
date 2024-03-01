/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:38:28 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:58:36 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Richiamata nel caso di entrambi elementi posizionati nella prima metà
static void	one_one(t_stack *s)
{
	while (s->i_b != 0 && s->i_a != 0)
	{
		rr(s);
		s->i_a--;
		s->i_b--;
	}
	while (s->i_a != 0)
	{
		ra(s);
		s->i_a--;
	}
	while (s->i_b != 0)
	{
		rb(s);
		s->i_b--;
	}
}

//Richiamata nel caso di entrambi elementi posizionati nella seconda metà
static void	two_two(t_stack *s)
{
	int	i;

	i = -1;
	if ((s->lenght_a - s->i_a) > (s->lenght_b - s->i_b))
	{
		while (++i < (s->lenght_b - s->i_b))
			rrr(s);
		i = -1;
		while (++i < ((s->lenght_a - s->i_a) - (s->lenght_b - s->i_b)))
			rra(s);
	}
	else
	{
		i = -1;
		while (++i < (s->lenght_a - s->i_a))
			rrr(s);
		i = -1;
		while (++i < (s->lenght_b - s->i_b) - (s->lenght_a - s->i_a))
			rrb(s);
	}
}

//elemento da spostare nella prima metà e destinazione nella seconda
static void	one_two(t_stack *s)
{
	while (s->i_a != 0)
	{
		ra(s);
		s->i_a--;
	}
	while (s->i_b < s->lenght_b)
	{
		rrb(s);
		s->i_b++;
	}
}

//elemento da spostare nella seconda metà e destinazione nella prima
static void	two_one(t_stack *s)
{
	while (s->i_a < s->lenght_a)
	{
		rra(s);
		s->i_a++;
	}
	while (s->i_b != 0)
	{
		rb(s);
		s->i_b--;
	}
}

//Funzione che sposta l'elemento in base alla casistica
void	move(t_stack *s, char type)
{
	int	half_a;
	int	half_b;

	half_a = half(s->lenght_a);
	half_b = half(s->lenght_b);
	if (s->i_a < half_a && s->i_b < half_b)
		one_one(s);
	else if (s->i_a < half_a && s->i_b >= half_b)
		one_two(s);
	else if (s->i_a >= half_a && s->i_b < half_b)
		two_one(s);
	else if (s->i_a >= half_a && s->i_b >= half_b)
		two_two(s);
	if (type == 'a')
		pa(s);
	else
		pb(s);
}
