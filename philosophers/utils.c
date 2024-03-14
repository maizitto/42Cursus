/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:28 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/14 17:35:50 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->write);
	time = get_time() - philo->start_time;
	if (!check_dead(philo))
		printf("%zu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->write);
}

void	ft_close(char *err, int nexit, int flag, t_table *table)
{
	int	i;

	i = -1;
	if (err)
		printf("%s\n", err);
	if (flag == 1)
	{
		while (++i < table->n_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->philo[i].lock);
			pthread_mutex_destroy(&table->philo[i].write);
		}
		pthread_mutex_destroy(&table->write);
		pthread_mutex_destroy(&table->lock);
	}
	clear_table(table);
	exit(nexit);
}

void	clear_table(t_table *table)
{
	if (table->pid)
		free(table->pid);
	if (table->forks)
		free(table->forks);
	if (table->philo)
		free(table->philo);
}

u_int64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("gettimeofday() error\n");
		exit(-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
