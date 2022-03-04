/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:56:51 by nbyrd             #+#    #+#             */
/*   Updated: 2022/02/21 15:23:02 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int sizer(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    return (i);
}

int set_envp(t_info *info, char **envp)
{
    int     i;
    char **new_env;
    int     counter;

    counter = sizer(envp);
    new_env = malloc(sizeof(char *) * (counter + 1));
    i = 0;
    while (envp[i])
    {
        new_env[i] = ft_strdup(envp[i]);
        i++;
    }
    info->env = new_env;
    return (1);
}

void    ft_env(t_info *info)
{
    int i;

    i = 0;
    while (info->env[i])
    {
        ft_putstr_fd(info->env[i], 1);
        ft_putchar_fd('\n', 1);
        i++;
    }
    exit(0);
}