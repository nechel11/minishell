/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:43 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/02 16:22:00 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_r(char *cmd)
{
	int	out;
	int	i;

	out = -1;
	i = 0;
	if (!ft_strncmp(cmd, ">>", 2))
	{
		while(cmd[i] == '>' || cmd[i] == ' ')
			i++;
		open(cmd[i],O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	ft_set_write(NULL, out);
}

int	redirect_l(char *cmd, t_info *info)
{
	close(info->pip.in);
	if (!ft_strncmp(cmd, "<<", 2))
	{
		while (*cmd == '<' || *cmd == ' ')
			cmd++;
		here_doc(cmd);
		info->pip.in = open(".tmp", O_RDONLY, 0777);
	}
	else
	{
		while (*cmd == '<' || *cmd == ' ')
			cmd++;
		info->pip.in = open(cmd, O_RDONLY, 0777);
		if (info->pip.in == -1)
		{
			ft_putstr_fd("msh: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(errno);
		}
	}
	return (info->pip.in);
}
void	here_doc(char *limitter)
{
	int	fd;
	char	*line;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(limitter, line ) || !line)
		{
			close(fd);
			free(line);
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	return ;
}