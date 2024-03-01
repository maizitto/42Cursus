/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:44:20 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/04 22:21:08 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa(t_stack *s)
{
	swap(s->stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *s)
{
	swap(s->stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *s)
{
	swap(s->stack_a);
	swap(s->stack_b);
	ft_printf("ss\n");
}
