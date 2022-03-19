/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:08:01 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/13 22:20:52 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		f1;
	int		f2;
	pid_t	pid;
	int		fd[2];
	char	**path;
	char	**cmd;
	char	*res;
	int		i;
	int		c;
	char	*limiter;
}			t_pipex;

void	put_close_error(int file);
void	put_open_error(char *str);
void	put_amount_error(int i);
void	put_error(void);
void	put_execve_error(char *cmd);
void	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);
void	ft_free_str_arr(char **arr);
void	ft_free(t_pipex *pipex);
char	**get_path(char **envp);
char	**get_cmd(char *arg);
void	ft_pipex(t_pipex *pipex);
void	find_path(t_pipex *pipex, int i);
void	change_fd(t_pipex *pipex, int f);
void	child(t_pipex *pipex, int f);

/*-----bonus-----*/

void	main_pt2(t_pipex *pipex);
void	init_heredoc(int argc, char **argv, char **envp, t_pipex *pipex);
void	create_tmp_file(t_pipex *pipex);

/*-----get_next_line-----*/

char	*ft_gstrchr(const char *s, int c);
size_t	ft_gstrlen(const char *s);
char	*ft_gsubstr(char const *s, unsigned int start, size_t len);
char	*ft_gstrdup(char *src);
char	*ft_gstrjoin(char *s1, char *s2);
char	*ft_getline(char **s, int rs);
char	*get_next_line(int fd);

#endif