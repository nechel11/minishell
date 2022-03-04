/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:13:25 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/02 13:15:16 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_path(char **path)
{
    int	i;

    i = 0;
    while(path[i])
    {
        free(path[i]);
        i++;
    }
    free(path);
}
char	*find_path(char *cmd, char **envp)
{
    int	i;
    char	**tmp_path;
    char	*path;
    char	*part_path;

    i = 0;
    while (envp[i] && !(ft_strnstr(envp[i], "PATH", 4)))
        i++;
    if (envp[i])  
        tmp_path = ft_split(envp[i] + 5, ':');
    else
        return (NULL);
    i = -1;
    while (tmp_path[++i])
    {
        part_path = ft_strjoin(tmp_path[i], "/");
        path = ft_strjoin(part_path, "/");
        free(part_path);
        if (access(path, F_OK) == 0)
      		return (path);
        free(path);
    }
    free_path(tmp_path);
    return (0);
}

void	ft_print_err_exec(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

char	**ft_exitt(char *cmd)
{
	char	**array;

	array = ft_split_squots(cmd);
	if (!ft_strncmp("exit", array[0], 5) || !ft_strncmp("exit ", array[0], 5))
	{
		if (array[1])
			exit(ft_atoi(array[1]));
		exit(0);
	}
	return (array);
}
void	execute(char *cmd, t_info *info)
{
	char *path;
	char	**array;

	if (!pipa_helper(cmd, info))
	{
		array = ft_exitt(cmd);
		path = find_path;
		if (!path)
			ft_print_err_exec(array[0]);
		execve(path, cmd, info->env);	
	}
	exit(errno);
}
