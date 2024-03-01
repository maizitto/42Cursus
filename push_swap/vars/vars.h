/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:30:30 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/09 18:33:30 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "../push_swap.h"

char	**ft_split(const char *str, char c);
int		count_words(const char *str, char c);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strdup(const char *src);

#endif