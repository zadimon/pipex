/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:08:45 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/14 22:44:45 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	main_pt2(t_pipex *pipex)
{
	ft_pipex(pipex);
	put_close_error(pipex->f2);
	ft_free(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		put_amount_error(0);
	else if (!(ft_strcmp(argv[1], "here_doc")) && argc == 6)
	{
		init_heredoc(argc, argv, envp, &pipex);
		create_tmp_file(&pipex);
		main_pt2(&pipex);
	}
	else if (!(ft_strcmp(argv[1], "here_doc")) && argc > 6)
		put_amount_error(1);
	else if (!(ft_strcmp(argv[1], "here_doc")) && argc == 5)
		put_amount_error(0);
	else
	{
		init_pipex(argc, argv, envp, &pipex);
		main_pt2(&pipex);
	}
	return (0);
}
