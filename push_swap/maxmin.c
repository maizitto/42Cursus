/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:23:27 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:27:21 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_max_a(t_stack *s)
{
	int	temp;
	int	i;
	int	p_temp;

	if (s->lenght_a == 0)
	{
		s->max_a.val = 0;
		return ;
	}
	temp = s->stack_a[0];
	p_temp = 0;
	i = 0;
	while (i < s->lenght_a)
	{
		if (temp < s->stack_a[i])
		{
			temp = s->stack_a[i];
			p_temp = i;
		}
		i++;
	}
	s->max_a.val = temp;
	s->max_a.pos = p_temp;
}

static void	get_max_b(t_stack *s)
{
	int	temp;
	int	i;
	int	p_temp;

	if (s->lenght_b == 0)
	{
		s->max_b.val = 0;
		return ;
	}
	temp = s->stack_b[0];
	p_temp = 0;
	i = 0;
	while (i < s->lenght_b)
	{
		if (temp < s->stack_b[i])
		{
			temp = s->stack_b[i];
			p_temp = i;
		}
		i++;
	}
	s->max_b.val = temp;
	s->max_b.pos = p_temp;
}

static void	get_min_a(t_stack *s)
{
	int	temp;
	int	p_temp;
	int	i;

	if (s->lenght_a == 0)
	{
		s->min_a.val = 0;
		return ;
	}
	temp = s->stack_a[0];
	p_temp = 0;
	i = 0;
	while (i < s->lenght_a)
	{
		if (temp > s->stack_a[i])
		{
			temp = s->stack_a[i];
			p_temp = i;
		}
		i++;
	}
	s->min_a.val = temp;
	s->min_a.pos = p_temp;
}

static void	get_min_b(t_stack *s)
{
	int	temp;
	int	p_temp;
	int	i;

	if (s->lenght_b == 0)
	{
		s->min_b.val = 0;
		return ;
	}
	temp = s->stack_b[0];
	p_temp = 0;
	i = 0;
	while (i < s->lenght_b)
	{
		if (temp > s->stack_b[i])
		{
			temp = s->stack_b[i];
			p_temp = i;
		}
		i++;
	}
	s->min_b.val = temp;
	s->min_b.pos = p_temp;
}

//Funzione per aggiornare la posizione e il valore di max e min
void	get_maxmin(t_stack *s)
{
	get_max_a(s);
	get_max_b(s);
	get_min_a(s);
	get_min_b(s);
}
