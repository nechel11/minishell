/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1echo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:42:40 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/15 18:11:06 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **line)
{
	int	i;

	i = 8;
	if (ft_strncmp(line[0], "echo -n", 6) == 0)
	{
		while(line[0][i] != '\0')
		{
			ft_putchar_fd(line[0][i], 1);
			i++;
		}
		return (1);
	}
	else if (ft_strncmp(line[0], "echo", 3) == 0)
	{
		i = 5;
		while(line[0][i] != '\0')
		{
			ft_putchar_fd(line[0][i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}