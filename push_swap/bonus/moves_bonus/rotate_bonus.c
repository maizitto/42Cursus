/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:39:59 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 00:33:13 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	rotate_b(int *stack, int length)
{
	int	temp;
	int	i;

	i = -1;
	temp = stack[0];
	while (++i < length - 1)
		stack[i] = stack[i + 1];
	stack[length - 1] = temp;
}

void	ra_b(t_stack *s)
{
	rotate_b(s->stack_a, s->lenght_a);
}

void	rb_b(t_stack *s)
{
	rotate_b(s->stack_b, s->lenght_b);
}

void	rr_b(t_stack *s)
{
	rotate_b(s->stack_a, s->lenght_a);
	rotate_b(s->stack_b, s->lenght_b);
}
