/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/02 13:41:23 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main (int argc, char **argv, char **envp)
{
	t_info	info;
	
	ft_init(&info,argc, argv);
	set_envp(&info, envp);
	while (!info.exit)
	{
		ft_parsing(&info);
	}
	return (0);
}