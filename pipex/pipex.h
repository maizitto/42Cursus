/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:40:28 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/28 13:01:12 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# include "gnl/get_next_line.h"

int		ft_error(void);
void	ft_execute(char **envp, char *argv);

char	*ft_strnstr(const char *s, const char *to_find, size_t len);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*epur(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_close(char **av);

#endif
