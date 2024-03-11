/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:39:50 by maizitto          #+#    #+#             */
/*   Updated: 2024/03/11 11:42:06 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 6)
		ft_close("Error: Invalid Inputs", -1);
	else
	{
		is_valid(argv);
		
	}
}
