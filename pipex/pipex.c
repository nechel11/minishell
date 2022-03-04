/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:03:11 by zafar             #+#    #+#             */
/*   Updated: 2022/03/03 10:32:22 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_cycle(char ***cmd, t_info *info, int i)
{
	int	pid;

	pipe(info->pip.rpipe);
	pid = fork_and_chain(info->pip.lpipe, info->pip.rpipe, cmd[i], info);
	close(info->pip.lpipe[0]);
	close(info->pip.lpipe[1]);
	info->pip.lpipe[0] = info->pip.rpipe[0];
	info->pip.lpipe[1] = info->pip.rpipe[1];
	i++;
	return (pid);
}

void	if_count_no_one(int i, int flag, char ***cmd, t_info *info)
{
	if (info->count != 1 && flag == 1)
	{
		info->pip.lpipe[0] = info->pip.rpipe[0];
		info->pip.lpipe[1] = info->pip.rpipe[1];
	}
	if (info->count != 1 && flag == 2)
	{
		info->pid = fork_and_chain(info->pip.lpipe, NULL, cmd[i], info);
		close(info->pip.lpipe[0]);
		close(info->pip.lpipe[1]);
	}
}

void	pipex(char ***cmd, t_info *info)
{
	int	i;
	int	count;
	int	pid;
	int	status;

	count = get_count_cmd(cmd);
	i = 1;
	info->count = count;
	if (count != 1)
		pipe(info->pip.rpipe);
	pid = fork_and_chain(NULL, info->pip.rpipe, cmd[0], info);
	if_count_no_one(i, 1, cmd, info);
	while (i < count - 1)
		pid = pipe_cycle(cmd, info, i++);
	info->pid = pid;
	if_count_no_one(i, 2, cmd, info);
	waitpid(info->pid, &status, 0);
	ft_convert_error(WEXITinfoATUS(status));
	if ((!cmd[++i] && count != 1 && WEXITinfoATUS(status) != 2) \
	|| (WEXITinfoATUS(status) != 2 && count == 1))
		ft_check_buildins(cmd[count - 1], info, count);
	ft_reinit_pip(info);
}


