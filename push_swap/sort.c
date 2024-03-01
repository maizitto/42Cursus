/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:51:06 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:59:16 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//calcola la posizione ottimale dove inserire 
//il valore di stack_b[i] nello stack_a
void	index_a(t_stack *s, int i)
{
	int	j;

	j = 0;
	s->i_temp_a = 0;
	s->i_temp_b = i;
	get_maxmin(s);
	if (s->stack_b[i] > s->max_a.val || s->stack_b[i] < s->min_a.val)
		s->i_temp_a = s->min_a.pos;
	while (j < s->lenght_a - 1)
	{
		if (s->stack_b[i] > s->stack_a[j] && s->stack_b[i] < s->stack_a[j + 1])
			s->i_temp_a = j + 1;
		j++;
	}
}

//calcola la posizione ottimale dove inserire 
//il valore di stack_a[i] nello stack_b
void	index_b(t_stack *s, int i)
{
	int	j;

	j = 0;
	s->i_temp_a = i;
	s->i_temp_b = 0;
	if (s->stack_a[i] > s->max_b.val || s->stack_a[i] < s->min_b.val)
		s->i_temp_b = s->max_b.pos;
	while (j < s->lenght_b - 1)
	{
		if (s->stack_a[i] < s->stack_b[j] && s->stack_a[i] > s->stack_b[j + 1])
			s->i_temp_b = j + 1;
		j++;
	}
}

//sposta da stack_a a stack_b n - 3 valori, richiamando le funzioni
//che verificano quale numero ha il costo computazionale miniore
static void	sort_b_three(t_stack *s)
{
	int	i;

	while (s->lenght_a > 3 && !is_sorted(s))
	{
		i = -1;
		while (++i < s->lenght_a)
		{
			index_b(s, i);
			count_mv(s, 'b');
		}
		move(s, 'b');
	}
}

//una volta completato il passaggio/ordinamento di n - 3 valori 
//sullo stack_b li inserisce nuovamente nello stack_a
static void	back_a(t_stack *s)
{
	int	i;

	while (s->lenght_b > 0)
	{
		i = -1;
		while (++i < s->lenght_b)
		{
			index_a(s, i);
			count_mv(s, 'a');
		}
		move(s, 'a');
	}
}

//Sort per n > 4 numeri
void	sort(t_stack *s)
{
	if (s->lenght_a > 3 && !is_sorted(s))
		pb(s);
	if (s->lenght_a > 3 && !is_sorted(s))
		pb(s);
	if (s->lenght_a > 3 && !is_sorted(s))
		sort_b_three(s);
	if (!is_sorted(s))
		sort_three(s);
	back_a(s);
	final(s);
}
