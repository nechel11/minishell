/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <nbyrd>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:24:56 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/02 13:24:56 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	contain(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!ft_strncmp(str[i], "<<", 2))
			return (1);
		i++;
	}
	return (0);
}

int ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}