/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:27:54 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/14 17:56:16 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	table->philo[0].left = &table->forks[0];
	table->philo[0].right = &table->forks[table->n_philo - 1];
	i = -1;
	while (++i < table->n_philo)
	{
		table->philo[i].left = &table->forks[i];
		if (i + 1 == table->n_philo)
			table->philo[i].right = &table->forks[0];
		else
			table->philo[i].right = &table->forks[i + 1];
	}
}

static void	init_table(char **argv, int argc, t_table *table)
{
	table->n_philo = (int)ft_atoi(argv[1]);
	table->death_time = (u_int64_t)ft_atoi(argv[2]);
	table->eat_time = (u_int64_t)ft_atoi(argv[3]);
	table->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		table->meals = (int) ft_atoi(argv[5]);
	else
		table->meals = -1;
	table->n_completed = 0;
	table->n_dead = 0;
	pthread_mutex_init(&table->lock, NULL);
	pthread_mutex_init(&table->write, NULL);
	table->pid = malloc(sizeof(pthread_t) * table->n_philo);
	if (!table->pid)
		ft_close("ERROR\n", -1, 0, table);
	table->philo = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philo)
		ft_close("ERROR\n", -1, 0, table);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
		ft_close("ERROR\n", -1, 0, table);
}

static void	init_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table ->n_philo)
	{
		table->philo[i].table = table;
		table->philo[i].id = i + 1;
		table->philo[i].death_time = table->death_time;
		table->philo[i].sleep_time = table->sleep_time;
		table->philo[i].eat_time = table->eat_time;
		table->philo[i].start_time = get_time();
		table->philo[i].last_meal = get_time();
		table->philo[i].n_meals = 0;
		table->philo[i].eating = 0;
		table->philo[i].dead = 0;
		pthread_mutex_init(&table->philo[i].lock, NULL);
		pthread_mutex_init(&table->philo[i].write, NULL);
	}
}

void	init(char **argv, int argc, t_table *table)
{
	init_table(argv, argc, table);
	init_forks(table);
	init_philos(table);
}
