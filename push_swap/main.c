/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:55:44 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/23 09:18:15 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s;

	if (argc > 1 && check_args(argc, argv, &s))
	{
		push_swap(&s);
		ft_close(&s, 9);
	}
	return (0);
}
