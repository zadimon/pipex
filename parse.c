/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:06:20 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/13 15:47:15 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->f1 = open(argv[1], O_RDONLY);
	if (pipex->f1 == -1)
		put_open_error(argv[1]);
	pipex->f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->f2 == -1)
		put_open_error(argv[argc - 1]);
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->path = get_path(envp);
	pipex->i = argc - 3;
	pipex->c = 2;
}

void	ft_free_str_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free(t_pipex *pipex)
{
	ft_free_str_arr(pipex->path);
}

char	**get_path(char **envp)
{
	char	*path;
	char	**res;
	int		i;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			break ;
		i++;
	}
	path = ft_strtrim(envp[i], "PATH=");
	res = ft_split(path, ':');
	free(path);
	return (res);
}

char	**get_cmd(char *arg)
{
	char	**res;

	res = ft_split(arg, ' ');
	return (res);
}
