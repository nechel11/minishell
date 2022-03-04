/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1pwd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:37:28 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/15 17:39:50 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return (1);
	}
	else
		return (0);
}