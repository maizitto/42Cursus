/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:30:03 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:20:23 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verifica ordinamento
int	is_sorted(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->lenght_a - 1)
	{
		if (s->stack_a[i] > s->stack_a[i + 1])
			return (0);
	}
	return (1);
}

//Ordinamento ottimizzato per 3 numeri
void	sort_three(t_stack *s)
{
	get_maxmin(s);
	if (is_sorted(s))
		return ;
	if (s->max_a.val == s->stack_a[2])
		sa(s);
	else if (s->max_a.val == s->stack_a[0] && s->min_a.val == s->stack_a[2])
	{
		sa(s);
		rra(s);
	}
	else if (s->max_a.val == s->stack_a[0])
		ra(s);
	else if (s->min_a.val == s->stack_a[0])
	{
		sa(s);
		ra(s);
	}
	else
		rra(s);
	get_maxmin(s);
}

//Ordinamento ottimizzato per 4 numeri
static void	sort_four(t_stack *s)
{
	if (s->stack_b[0] < s->min_a.val && s->lenght_b)
		pa(s);
	if (s->stack_b[0] > s->max_a.val && s->lenght_b)
	{
		pa(s);
		ra(s);
	}
	else if (s->stack_b[0] > s->min_a.val && s->stack_b[0] < s->stack_a[1]
		&& s->lenght_b)
	{
		ra(s);
		pa(s);
		rra(s);
	}
	else if (s->stack_b[0] > s->min_a.val && s->stack_b[0] > s->stack_a[1]
		&& s->lenght_b)
	{
		ra(s);
		ra(s);
		pa(s);
		rra(s);
		rra(s);
	}
}

void	push_swap(t_stack *s)
{
	if (is_sorted(s))
		return ;
	if (s->lenght_a == 2)
		sa(s);
	if (s->lenght_a == 3)
		sort_three(s);
	if (s->lenght_a == 4)
	{
		pb(s);
		sort_three(s);
		sort_four(s);
	}
	if (s->lenght_a > 4)
		sort(s);
	else
		return ;
}
