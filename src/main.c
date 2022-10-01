/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:43 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:47:36 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	extern char	*rl_line_buffer;

	init_signals();
	(void)argc;
	(void)argv;
	parse_env(envp);
	while (1)
	{
		input = readline("Dit is echt leuk: ");
		if (!input)
		{
			// When ctrl + D is pushed, this will put out the message that it has stopped.
			ft_putendl_fd("exit", 1);
			exit(0);
		}
		if (input && *input)
			add_history(input);
		ft_snorlexer(input);
		free(input);
		input = NULL;
	}
	return (0);
}
