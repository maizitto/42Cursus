/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:28 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/11 11:12:01 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_close(char *err, int nexit)
{
	put_str(err);
	exit(nexit);
}
