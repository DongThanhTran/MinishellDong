/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:21 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:42:43 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_quotes(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '\"')
	{
		i = 1;
		while (input[i] && input[i] != '\"')
		{
			i++;
		}
	}
	else if (input[0] == '\'')
	{
		i = 1;
		while (input[i] && input[i] != '\'')
			i++;
	}
	return (i);
}
