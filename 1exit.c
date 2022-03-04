/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:43:46 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/03 09:43:46 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strisdig(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required", 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_exit(char *argv, t_info *info)
{
	char **splitted;

	splitted = ft_split_wquots(argv);
	if (splitted[1] && splitted[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments", 2);
		ft_putchar_fd('\n', 2);
		exit(ft_atoi(splitted[1]));
	}
	if (splitted[1] && !ft_strisdig(splitted[1]))
		info->exit = 255;
	else if (splitted[1])
		info->exit = ft_atoi(splitted[1]);
	else
		info->exit = 1;
	ft_myfree(splitted);
	exit(info->exit);
}