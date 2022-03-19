/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:35:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/13 22:36:10 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_fd(t_pipex *pipex, int f)
{
	if (f == -1)
		exit(EXIT_FAILURE);
	if (dup2(f, STDIN_FILENO) == -1)
		put_error();
	if (pipex->i == 1)
	{
		if (dup2(pipex->f2, STDOUT_FILENO) == -1)
			put_error();
		put_close_error(pipex->fd[1]);
		put_close_error(pipex->f2);
	}
	else
	{
		if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
			put_error();
	}
	put_close_error(pipex->fd[0]);
}

void	find_path(t_pipex *pipex, int i)
{
	char	*tmp;

	tmp = ft_strjoin("/", pipex->cmd[0]);
	pipex->res = ft_strjoin(pipex->path[i], tmp);
	free(tmp);
	execve(pipex->res, pipex->cmd, pipex->envp);
	free(pipex->res);
}

void	child(t_pipex *pipex, int f)
{
	int		i;

	change_fd(pipex, f);
	pipex->cmd = get_cmd(pipex->argv[pipex->c]);
	i = 0;
	if (ft_strchr(pipex->cmd[0], '/'))
		execve(pipex->cmd[0], pipex->cmd, pipex->envp);
	else
	{
		while (pipex->path[i] != 0)
		{
			find_path(pipex, i);
			i++;
		}
	}
	put_execve_error(pipex->cmd[0]);
}

void	ft_pipex(t_pipex *pipex)
{
	int		status;
	int		f;

	f = pipex->f1;
	while (pipex->i > 0)
	{
		if (pipe(pipex->fd) == -1)
			put_error();
		pipex->pid = fork();
		if (pipex->pid < 0)
			put_error();
		if (pipex->pid == 0)
			child(pipex, f);
		put_close_error(f);
		f = pipex->fd[0];
		pipex->c++;
		pipex->i--;
		put_close_error(pipex->fd[1]);
	}
	put_close_error(pipex->fd[0]);
	waitpid(pipex->pid, &status, 0);
}
