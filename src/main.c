/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:43 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/26 23:18:10 by mlvb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_shell	shell;
	
	init_signals(); //Might need to move init signals into while, in case when ./minishell is entered as prompt in the current session.(SHL level?)
	(void)argc;
	(void)argv;
	parse_env(envp);
	while (1)
	{
		input = readline("Minishell: ");
		if (!input)
		{
			// When ctrl + D is pushed, this will put out the message that it has stopped.
			ft_putendl_fd("exit", 1);
			exit(0);
		}
		if (input && *input)
			add_history(input);
		shell.lexer = ft_snorlexer(input);
		// parser("HELLO", shell.lexer);
		free(input);
		input = NULL;
	}
	return (0);
}
