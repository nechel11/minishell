/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:17:03 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/02 13:17:03 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		rl_on_new_line();
		rl_replace_line("\0", 0);
		rl_redisplay();
		g_error = 1;
	}
}

void	sig_void(int sig)
{
	(void)sig;
}

void	sig_void2(int sig)
{
	(void)sig;
	g_error = 1;
	rl_on_new_line();
	rl_redisplay();
	rl_catch_signals = 0;
	close(0);
	exit(0);
}