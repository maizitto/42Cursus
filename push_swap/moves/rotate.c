/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:39:59 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/08 16:28:49 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(int *stack, int length)
{
	int	temp;
	int	i;

	i = -1;
	temp = stack[0];
	while (++i < length - 1)
		stack[i] = stack[i + 1];
	stack[length - 1] = temp;
}

void	ra(t_stack *s)
{
	rotate(s->stack_a, s->lenght_a);
	ft_printf("ra\n");
}

void	rb(t_stack *s)
{
	rotate(s->stack_b, s->lenght_b);
	ft_printf("rb\n");
}

void	rr(t_stack *s)
{
	rotate(s->stack_a, s->lenght_a);
	rotate(s->stack_b, s->lenght_b);
	ft_printf("rr\n");
}
