/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:20:38 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/03 09:23:25 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_do_redir_left_deep(t_info *info, int in)
{
	if (info->last_r[info->pip.curr_index] == 2)
	{
		close(in);
		in = open(".tmp", O_RDONLY, 0777);
		info->pip.in = in;
	}
}