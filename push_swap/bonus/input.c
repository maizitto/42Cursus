/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:44:03 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/10 12:56:49 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (*s1 && *s2 && i < (n - 1) && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

//verifica che il comando sia valido
int	check_input(char *input)
{
	if (!(ft_strncmp(input, "pa\n", 3)) || !(ft_strncmp(input, "pb\n", 3))
		|| !(ft_strncmp(input, "sa\n", 3)) || !(ft_strncmp(input, "sb\n", 3))
		|| !(ft_strncmp(input, "ss\n", 3)) || !(ft_strncmp(input, "ra\n", 3))
		|| !(ft_strncmp(input, "rb\n", 3)) || !(ft_strncmp(input, "rr\n", 3))
		|| !(ft_strncmp(input, "rra\n", 4)) || !(ft_strncmp(input, "rrb\n", 4))
		|| !(ft_strncmp(input, "rrr\n", 4)))
		return (1);
	else
		return (0);
}

//esegue il comando preso da input
void	execute_input(char *input, t_stack *s)
{
	if (!ft_strncmp(input, "pa\n", 3))
		pa_b(s);
	if (!ft_strncmp(input, "pb\n", 3))
		pb_b(s);
	if (!ft_strncmp(input, "sa\n", 3))
		sa_b(s);
	if (!ft_strncmp(input, "sb\n", 3))
		sb_b(s);
	if (!ft_strncmp(input, "ss\n", 3))
		ss_b(s);
	if (!ft_strncmp(input, "ra\n", 3))
		ra_b(s);
	if (!ft_strncmp(input, "rb\n", 3))
		rb_b(s);
	if (!ft_strncmp(input, "rr\n", 3))
		rr_b(s);
	if (!ft_strncmp(input, "rra\n", 4))
		rra_b(s);
	if (!ft_strncmp(input, "rrb\n", 4))
		rrb_b(s);
	if (!ft_strncmp(input, "rrr\n", 4))
		rrr_b(s);
}
