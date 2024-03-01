/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:40:27 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/15 10:37:20 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		nlen(long n);
char	*ft_itoa(long n);
int		ft_putnbr_base(long n, int type);
int		ft_u_putnbr(unsigned int n);
int		ft_p_putnbr(void *ptr, int i);

#endif
