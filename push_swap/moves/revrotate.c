/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:39:59 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/09 13:32:51 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	revrotate(int *stack, int length)
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

void	rra(t_stack *s)
{
	revrotate(s->stack_a, s->lenght_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
{
	revrotate(s->stack_b, s->lenght_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *s)
{
	revrotate(s->stack_a, s->lenght_a);
	revrotate(s->stack_b, s->lenght_b);
	ft_printf("rrr\n");
}
