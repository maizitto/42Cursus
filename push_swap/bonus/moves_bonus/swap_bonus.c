/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:44:20 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 09:52:57 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	swap_b(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa_b(t_stack *s)
{
	swap_b(s->stack_a);
}

void	sb_b(t_stack *s)
{
	swap_b(s->stack_b);
}

void	ss_b(t_stack *s)
{
	swap_b(s->stack_a);
	swap_b(s->stack_b);
}
