/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:16:41 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/13 21:47:04 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_close_error(int file)
{
	if (file != -1)
	{
		if (close(file) == -1)
			put_error();
	}
}

void	put_execve_error(char *cmd)
{
	if (ft_strchr(cmd, '/'))
		put_open_error(cmd);
	else
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
	exit(EXIT_FAILURE);
}

void	put_error(void)
{
	ft_putstr_fd("zsh: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}

void	put_amount_error(int i)
{
	if (i == 1)
		ft_putendl_fd("Too many arguments", 2);
	else
		ft_putendl_fd("Too few arguments", 2);
	exit(EXIT_FAILURE);
}

void	put_open_error(char *str)
{
	ft_putstr_fd("zsh: no such file or directory: ", 2);
	ft_putendl_fd(str, 2);
}
