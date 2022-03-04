/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:17:56 by nbyrd             #+#    #+#             */
/*   Updated: 2022/02/21 14:17:56 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_error(t_info *info, int i)
{
    if (i == 1)
        ft_putstr_fd("malloc error\n", 2);
    exit(1);

    if (i == 3)
    {
        ft_putstr_fd("msh: syntax error near unexpected token '|'", 2);
		ft_putstr_fd("\n", 2);
    }

    if (i == 4)
    {
        ft_putstr_fd("minishell: parse error", 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}