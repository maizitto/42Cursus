/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:52:21 by mmasitto          #+#    #+#             */
/*   Updated: 2024/03/15 11:59:43 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	msg("is thinking", philo);
}

void	dream(t_philo *philo)
{
	msg("is sleeping", philo);
	usleep(philo->sleep_time);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	msg("has taken a fork", philo);
	pthread_mutex_lock(philo->left);
	msg("has taken a fork", philo);
	philo->eating = 1;
	msg("is eating", philo);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_time();
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal);
	usleep(philo->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}
