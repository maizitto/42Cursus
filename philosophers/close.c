/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:28 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/11 17:28:43 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_close(char *err, int nexit, int flag, t_table *table)
{
	int	i;

	i = -1;
	put_str(err);
	if (flag == 1)
	{
		while (++i < table->n_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->philo[i].lock);
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

