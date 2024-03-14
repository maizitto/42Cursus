/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:39:50 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/14 23:51:00 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid Inputs\n");
		return (-1);
	}
	else
	{
		if (ft_atoi(argv[1]) == 1)
		{
			printf("0 1 has taken a fork\n");
			usleep(ft_atoi(argv[2]));
			printf("%ld 1 died\n", ft_atoi(argv[2]));
			return (0);
		}
		is_valid(argv);
		init(argv, argc, &table);
		start(&table);
		ft_close(NULL, 1, 1, &table);
	}
}
