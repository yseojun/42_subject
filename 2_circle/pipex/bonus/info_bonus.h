/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:39:47 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/01 16:13:14 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pid
{
	pid_t			pid;
	struct s_pid	*next;
}	t_pid;

typedef struct s_info
{
	int				ac;
	char			**av;
	char			**envp;
	int				now_idx;
	int				infile_fd;
	int				outfile_fd;
	int				heredoc;
	char			*limiter;
	char			**path;
	struct s_pid	*pids;
}	t_info;

void	run_pipe(t_info *info);
void	run_command(t_info *info);
void	child(int *pipefd, int prev_fd, t_info *info);
void	wait_all(t_info *info);

void	init_info(t_info *info, int ac, char **av, char **envp);
char	**find_path_in_env(char **envp);
char	*make_real_path(char *path, char *command);
char	*find_command_in_path(char *command, char **path);
void	add_pid(t_info *info, pid_t	pid);

#endif