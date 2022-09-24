/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:43 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/24 12:05:33 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	(void)argc;
	(void)argv;
	parse_env(envp);
	while (1)
	{
		input = readline("Dit is echt leuk: ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		ft_snorlexer(input);
		free(input);
		input = NULL;
	}
	return (0);
}
