/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:56:09 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 09:54:12 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "vars/vars.h"
# include <limits.h>

typedef struct s_node
{
	int	val;
	int	pos;

}	t_node;

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	char	**check;
	t_node	min_a;
	t_node	min_b;
	t_node	max_a;
	t_node	max_b;
	int		lenght_a;
	int		lenght_b;
	int		half_a;
	int		half_b;
	int		i_temp_a;
	int		i_temp_b;
	int		i_a;
	int		i_b;
	int		t_mov;
	int		n_mov;

}	t_stack;

int		check_args(int argc, char **args_main, t_stack *a);
void	ft_free(char **arr);
int		ft_close(t_stack *s, int flag);
void	init(t_stack *s);
int		is_sorted(t_stack *a);
void	sort_three(t_stack *a);
void	get_maxmin(t_stack *s);
void	push_swap(t_stack *a);
void	print_stack(t_stack *a);
void	sort(t_stack *s);
int		half(int length);
void	count_mv(t_stack *s, char type);
void	aux_moves(t_stack *s, char type);
void	move(t_stack *s, char type);
void	index_a(t_stack *s, int i);
void	final(t_stack *s);

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
void	pa(t_stack *t);
void	pb(t_stack *t);

#endif