/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:03:54 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/14 13:08:26 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		init_pipex(argc, argv, envp, &pipex);
		ft_pipex(&pipex);
		ft_free(&pipex);
		put_close_error(pipex.f2);
	}
	else if (argc > 5)
		put_amount_error(1);
	else
		put_amount_error(0);
	return (0);
}
