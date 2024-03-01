/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:56:31 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:02:27 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	push_b(int *src, int *dest, int l_src, int l_dest)
{
	int	i;
	int	temp;

	if (l_src == 0)
		return ;
	temp = src[0];
	i = -1;
	while (++i < l_src - 1)
		src[i] = src[i + 1];
	if (l_dest == 0)
		dest[0] = temp;
	else
	{
		while (l_dest > 0)
		{
			dest[l_dest] = dest[l_dest - 1];
			l_dest--;
		}
		dest[0] = temp;
	}
}

void	pa_b(t_stack *t)
{
	push_b(t->stack_b, t->stack_a, t->lenght_b, t->lenght_a);
	t->lenght_b--;
	t->lenght_a++;
	get_maxmin(t);
}

void	pb_b(t_stack *t)
{
	push_b(t->stack_a, t->stack_b, t->lenght_a, t->lenght_b);
	t->lenght_b++;
	t->lenght_a--;
	get_maxmin(t);
}
