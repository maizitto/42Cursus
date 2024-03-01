/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:15:51 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:59:33 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//chiusura e pulizia del programma
int	ft_close(t_stack *s, int flag)
{
	if (!flag)
	{
		write(2, "Error\n", 6);
		ft_free(s->check);
	}
	else if (flag == 2)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s->stack_b);
	}
	else
	{
		free(s->stack_a);
		free(s->stack_b);
	}
	exit(0);
}

//pulizia di un array di stringhe
void	ft_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free (arr);
}

//inizializzare la struct
void	init(t_stack *s)
{
	s->half_a = 0;
	s->half_b = 0;
	s->i_a = 0;
	s->i_b = 0;
	s->i_temp_a = 0;
	s->i_temp_b = 0;
	s->n_mov = 0;
	s->t_mov = 0;
	s->check = NULL;
}

//printare le stack
void	print_stack(t_stack *s)
{
	int	i;

	i = -1;
	ft_printf("\n\n");
	ft_printf("Stack A: \n");
	if (s->lenght_a == 0)
		ft_printf("Empty\n");
	while (++i < s->lenght_a)
		ft_printf("%d\n", s->stack_a[i]);
	i = -1;
	ft_printf("\nStack B: \n");
	if (s->lenght_b == 0)
		ft_printf("Empty\n");
	while (++i < s->lenght_b)
		ft_printf("%d\n", s->stack_b[i]);
	ft_printf("\n\n");
}
