/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:28:02 by mmasitto          #+#    #+#             */
/*   Updated: 2024/03/01 11:06:46 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char **argv, int argc, int mode)
{
	int	fd;

	if (mode == 1)
	{
		if (!ft_strncmp("here_doc", argv[1], 8))
			fd = open(".temp", O_RDWR | O_CREAT | O_TRUNC, 0777);
		else
			fd = open(argv[1], O_RDONLY, 0777);
		if (fd == -1)
			ft_error();
		return (fd);
	}
	else
	{
		if (!ft_strncmp("here_doc", argv[1], 8))
			fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			ft_error();
		return (fd);
	}
}

static int	here_doc(int *fd, char **av)
{
	char	*temp;

	if (!ft_strncmp("here_doc", av[1], 8))
	{
		write(1, "here_doc>", 10);
		temp = get_next_line(0);
		while (temp && ft_strncmp(temp, av[2], ft_strlen(av[2])))
		{
			write(1, "here_doc>", 10);
			write(*fd, temp, ft_strlen(temp));
			free(temp);
			temp = get_next_line(0);
			if (!ft_strncmp(temp, av[2], ft_strlen(av[2])))
				break ;
		}
		free(temp);
		close(*fd);
		*fd = open(".temp", O_RDONLY, 0777);
		return (3);
	}
	return (2);
}

static void	ft_pipe(char *cmd, char **envp, int fdin)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_error();
	if (pid1)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid1, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			ft_execute(envp, cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc >= 5)
	{
		fd_in = ft_open(argv, argc, 1);
		fd_out = ft_open(argv, argc, 0);
		i = here_doc(&fd_in, argv);
		dup2(fd_in, STDIN_FILENO);
		unlink(".temp");
		dup2(fd_out, STDOUT_FILENO);
		ft_pipe(argv[i], envp, fd_in);
		while (++i < argc - 2)
			ft_pipe(argv[i], envp, 1);
		ft_execute(envp, argv[i]);
		close(fd_in);
		close(fd_out);
	}
	else
		write(2, "Error: Invalid number parameters\n", 32);
}
