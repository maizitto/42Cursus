/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:16:54 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/22 12:09:29 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check se la stringa è un numero
static int	is_numb(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1])
			i++;
		else
			return (0);
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

//check se il parametro da inserire è già contenuto nell'array 
static int	ft_contains(char **args, int n, int argc, int flag)
{
	int	i;
	int	count;
	int	x;

	i = -1;
	count = 0;
	x = 0;
	if (flag == 0)
		x = argc - 1;
	else
	{
		while (args[x])
			x++;
	}
	while (++i < x)
	{
		if (ft_atoi(args[i]) == n)
			count++;
	}
	if (count > 1)
		return (0);
	else
		return (1);
}

//inizializza gli stack e riempe stack_a
static int	init_stack(char **args, t_stack *s)
{
	int	i;

	i = 0;
	if (!args)
		ft_close(s, 0);
	while (args[i])
		i++;
	s->lenght_a = i;
	s->stack_a = (int *)malloc(sizeof(int) * i);
	if (!s->stack_a)
		ft_close(s, 0);
	s->stack_b = (int *)malloc(sizeof(int) * i);
	if (!s->stack_b)
		ft_close(s, 0);
	s->lenght_b = 0;
	i = -1;
	while (args[++i])
		s->stack_a[i] = ft_atoi(args[i]);
	ft_free(args);
	init(s);
	get_maxmin(s);
	return (1);
}

//funzione richiamata nel caso che i parametri da terminale
//vengano inseriti separati come ./push_swap 1 2 3 4 5 e non come
//./push_swap "1 2 3 4 5" stringa unica
static char	**fill_args(int argc, char **args_main)
{
	char	**args;
	int		i;

	i = 0;
	args = (char **)malloc(sizeof(char *) * (argc));
	if (!args)
		return (0);
	args[argc - 1] = NULL;
	while (args_main[++i])
		args[i - 1] = ft_strdup(args_main[i]);
	return (args);
}

//verifica i numeri inseriti e li setta nello stack_a
int	check_args(int argc, char **args_main, t_stack *s)
{
	int		i;
	long	tmp;

	i = -1;
	if (argc == 2)
	{
		s->check = ft_split(args_main[1], ' ');
		if (!s->check || !s->check[0])
			ft_close(s, 0);
	}
	else if (argc > 2)
		s->check = fill_args(argc, args_main);
	while (s->check[++i])
	{
		if (!s->check[i][0])
			ft_close(s, 0);
		tmp = ft_atoi(s->check[i]);
		if (!is_numb(s->check[i]))
			ft_close(s, 0);
		if (!ft_contains(s->check, tmp, argc, 1))
			ft_close(s, 0);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_close(s, 0);
	}
	return (init_stack(s->check, s));
}
