/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:48 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/11 12:17:48 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILOS 200

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				n_meals;
	int				state;
	int				eating;
	u_int64_t		death_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}	t_philo;

typedef struct s_table
{
	pthread_t		pid;
	int				n_philo;
	int				meals;
	int				n_dead;
	int				n_completed;
	t_philo			*philo;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_table;

void	ft_close(char *err, int nexit);
void	put_str(char *str);
int		is_valid(char **argv);

#endif