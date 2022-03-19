/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:25:08 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/14 22:43:37 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_heredoc(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (pipex->f2 == -1)
		put_open_error(argv[argc - 1]);
	pipex->limiter = argv[2];
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->path = get_path(envp);
	pipex->i = 2;
	pipex->c = 3;
}

void	create_tmp_file(t_pipex *pipex)
{
	char	*line;
	char	*tmp;

	if (pipe(pipex->fd) == -1)
		put_error();
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
		if (ft_strcmp(line, pipex->limiter) == 0)
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(line, "\n");
		write(pipex->fd[1], tmp, ft_strlen(tmp));
		free(line);
		free(tmp);
	}
	put_close_error(pipex->fd[1]);
	pipex->f1 = pipex->fd[0];
}
