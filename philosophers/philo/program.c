/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:34:42 by mmasitto          #+#    #+#             */
/*   Updated: 2024/03/15 11:59:43 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (*philo->dead)
	{
		pthread_mutex_unlock(&philo->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

void	*rout(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!check_dead(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (ptr);
}

int	start(t_table *table)
{
	pthread_t	ch;
	int			i;

	i = -1;
	if (pthread_create(&ch, NULL, &checker, table))
		ft_close("Error\n", -1, 1, table);
	while (++i < table->n_philo)
	{
		if (pthread_create(&table->philo[i].t1, NULL, &rout, &table->philo[i]))
			ft_close("Error\n", -1, 1, table);
	}
	if (pthread_join(ch, NULL))
		ft_close("Error\n", -1, 1, table);
	i = -1;
	while (++i < table->n_philo)
	{
		if (pthread_join(table->philo[i].t1, NULL))
			ft_close("Error\n", -1, 1, table);
	}
	return (0);
}
