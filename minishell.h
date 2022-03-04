/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:36:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/03 09:39:26 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "minishell> "

# include "./bible2/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>              
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <errno.h>

int	g_error;

typedef struct s_pip {
	int	lpipe[2];
	int	rpipe[2];
	int	in;
	int	curr_index;
	int	last_index;
}	t_pip;

typedef struct s_info {
	char	*line;
	char	**commands;
	char	***cmd;
	char	**splited;
	int		promptflag;
	int		argc;
	char	**argv;
	char	**env;
	int		exit;
	int		err;
	int		count;
	int		pid;
	int		*last_r;
	//t_list	*vars;
	t_pip	pip;
}	t_info;

int	cmd_count(t_info *info);
void	ft_set_read(int *lpipe, int in);
void	ft_set_write(int *rpipe, int out);
int	pipa_helper(char *arg, t_info *info);
void	do_redir_right(char **cmd, int *rpipe, t_info *info);
void	redirect_r(char *cmd);
int	ft_echo(char **line);
int set_envp(t_info *info, char **envp);
void    ft_env(t_info *info);
int	ft_pwd(void);
int ft_error(t_info *info, int i);
char	*find_path(char *cmd, char **envp);
void	ft_print_err_exec(char *cmd);
char	**ft_exitt(char *cmd);
void	execute(char *cmd, t_info *info);
void ft_init(t_info *st,  int argc, char **argv);
int ft_strcmp(char *str1, char *str2);
void	here_doc(char *limitter);
void	ft_do_redir_left_deep(t_info *info, int in);
void	do_redir_left(char **cmd, int *lpipe, t_info *info);
void	do_redir_right(char **cmd, int *rpipe, t_info *info);
void	do_command(char **cmd, int *rpipe, t_info *info);
void	**ft_myfree(char **str);
void	ft_exit(char *argv, t_info *info);
void	sig_handler(int sig);
void	sig_void(int sig);
void	sig_void2(int sig);
int	fork_and_chain(int *lpipe, int *rpipe, char **cmd, t_info *info);
void	pipex(char ***cmd, t_info *info);

#endif