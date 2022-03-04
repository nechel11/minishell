/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/02 14:17:44 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ft_init(t_info *st,  int argc, char **argv)
{
    st->line = NULL;
	st->commands = NULL;
	st->splited = NULL;
	st->promptflag = 1;
	st->argc = argc;
	st->argv = argv;
	st->env = NULL;
	st->exit = 0;
	g_error = 0;
	st->pip.lpipe[0] = -1;
	st->pip.lpipe[1] = -1;
	st->pip.rpipe[0] = -1;
	st->pip.rpipe[1] = -1;
	st->pip.in = -1;
	st->last_r = NULL;
	st->pip.curr_index = 0;
	//set_shlvl(st);
	//rl_catch_signals = 0;
}