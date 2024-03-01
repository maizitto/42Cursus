/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:39:59 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 00:33:16 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	revrotate_b(int *stack, int length)
{
	int	temp;
	int	i;

	i = length - 1;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	if (i == 0)
		stack[i] = temp;
}

void	rra_b(t_stack *s)
{
	revrotate_b(s->stack_a, s->lenght_a);
}

void	rrb_b(t_stack *s)
{
	revrotate_b(s->stack_b, s->lenght_b);
}

void	rrr_b(t_stack *s)
{
	revrotate_b(s->stack_a, s->lenght_a);
	revrotate_b(s->stack_b, s->lenght_b);
}
