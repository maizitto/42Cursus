/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:51:05 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 00:05:23 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../printf/ft_printf.h"
# include "../vars/vars.h"
# include <limits.h>
# include "../push_swap.h"
# include "gnl/get_next_line.h"

int		check_input(char *input);
void	execute_input(char *input, t_stack *s);

void	sa_b(t_stack *s);
void	sb_b(t_stack *s);
void	ss_b(t_stack *s);
void	ra_b(t_stack *s);
void	rb_b(t_stack *s);
void	rr_b(t_stack *s);
void	rra_b(t_stack *s);
void	rrb_b(t_stack *s);
void	rrr_b(t_stack *s);
void	pa_b(t_stack *t);
void	pb_b(t_stack *t);

#endif