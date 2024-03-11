/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:13:58 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/11 12:27:03 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_isspace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n'
		|| ch == '\r' || ch == '\f' || ch == '\v')
	{
		return (1);
	}
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (my_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (sign * number);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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

int	is_valid(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!is_numb(argv[i]))
			ft_close("Error: invalid inputs\n", -1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > MAX_PHILOS)
		ft_close("Error: wrong philosophers number\n", -1);
	return (1);
}
