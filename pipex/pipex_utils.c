/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:38:54 by zafar             #+#    #+#             */
/*   Updated: 2022/03/02 14:26:24 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_count(t_info *info)
{
	int	i;

	i = 0;
	while (info->cmd[i])
		i++;
	return (i);
}

void	ft_set_read(int *lpipe, int in)
{
	if (lpipe)
	{
		dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		close(lpipe[1]);
	}
	else
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
}

void	ft_set_write(int *rpipe, int out)
{
	if (rpipe)
	{
		dup2(rpipe[1], STDOUT_FILENO);
		close(rpipe[0]);
		close(rpipe[1]);
	}
	else
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}

int	pipa_helper(char *arg, t_info *info)
{
	if (!ft_strncmp("pwd ", arg, 4) || !ft_strncmp("pwd", arg, 4))
		ft_pwd();
	if (!ft_strncmp("env ", arg, 4) || !ft_strncmp("env", arg, 4))
		get_env(info);
	if (info->count != 1)
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7))
			exit(ft_export(arg, info));
		if (!ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6))
			exit(ft_unset(arg, info));
		if (!ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(ft_cd(arg, info));
	}
	else
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7) \
		|| !ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6) \
		|| !ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(0);
	}
	if (!ft_strncmp("echo ", arg, 5) || !ft_strncmp("echo", arg, 5))
		ft_echo(info->line);
	return (0);
}

int	fork_and_chain(int *lpipe, int *rpipe, char **cmd, t_info *info)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		signal(SIGINT, sig_void2);
		rl_catch_signals = 1;
		do_redir_left(cmd, lpipe, info);
		signal(SIGINT, sig_handler);
		do_redir_right(cmd, rpipe, info);
		do_command(cmd, rpipe, info);
	}
	else
	{
		if (contain(cmd))
			waitpid(pid, NULL, 0);
		else
			waitpid(pid, NULL, WNOHANG);
	}
	info->pip.curr_index++;
	return (pid);
}