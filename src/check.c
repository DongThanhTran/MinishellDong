/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:21 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/26 23:40:16 by mlvb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_quotes(char *input)
{
	int	i;

	if (input[0] == '\"')
	{
		i = 1;
		while (input[i] && input[i] != '\"')
			i++;
	}
	if (input[0] == '\'')
	{
		i = 1;
		while (input[i] && input[i] != '\'')
			i++;
	}
	return (i - 1);
}
