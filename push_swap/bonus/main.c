/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:16 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:48 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//fcheck dell'ordinamento
static int	is_sorted_b(t_stack *s)
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

int	main(int argc, char **argv)
{
	t_stack	s;
	char	*input;

	if (argc > 1 && check_args(argc, argv, &s))
	{
		while (1)
		{
			input = get_next_line(0);
			if (!input)
				break ;
			if (!check_input(input))
				ft_close(&s, 2);
			execute_input(input, &s);
		}
		if (is_sorted_b(&s))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
