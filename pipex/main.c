/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:40:26 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/28 13:01:57 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char **argv, char **envp, int *fd)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		ft_error();
	close(fd[0]);
	dup2(fd_in, 0);
	dup2(fd[1], 1);
	ft_execute(envp, argv[2]);
}

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_error();
	close(fd[1]);
	dup2(fd_out, 1);
	dup2(fd[0], 0);
	ft_execute(envp, argv[3]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == -1)
			ft_error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
		write(2, "Error: Invalid number parameters\n", 32);
	exit(0);
}
