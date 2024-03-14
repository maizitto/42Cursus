/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:03:38 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/15 00:00:15 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo *philo, size_t time)
{
	pthread_mutex_lock(&philo->meal);
	if (get_time() - philo->last_meal >= time && !philo->eating)
	{
		pthread_mutex_unlock(&philo->meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal);
	return (0);
}

static int	is_dead_all(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
	{
		if (is_dead(&table->philo[i], table->death_time))
		{
			msg("died", &table->philo[i]);
			table->philo[i].dead = 1;
			pthread_mutex_lock(&table->lock);
			table->n_dead = 1;
			pthread_mutex_unlock(&table->lock);
			return (1);
		}
	}
	return (0);
}

static int	eaten(t_table *table)
{
	int	i;
	int	completed;

	i = -1;
	completed = 0;
	if (table->meals == -1)
		return (0);
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->philo[i].lock);
		if (table->philo[i].n_meals >= table->meals)
			completed++;
		pthread_mutex_unlock(&table->philo[i].lock);
	}
	if (completed == table->n_philo)
	{
		pthread_mutex_lock(&table->lock);
		table->n_dead = 1;
		pthread_mutex_unlock(&table->lock);
		return (1);
	}
	return (0);
}

void	*checker(void *ptr)
{
	t_table	*pointer;

	pointer = (t_table *)ptr;
	while (1)
	{
		if (is_dead_all(pointer) || eaten(pointer))
			break ;
	}
	return (ptr);
}
