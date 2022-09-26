/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlammert <mlammert@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/24 16:32:02 by mlammert      #+#    #+#                 */
/*   Updated: 2022/09/25 14:22:14 by mlvb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int signum)
{
	extern int	rl_done;
	
	// This signal is triggered by ctrl + backslash
	// The subject says it shouldn't do anything. But there is an edge case i still need to figure out
	// Sometimes the output can be: Quit: 3 (or something) but i dont know when this happens
	// if (signum == SIGQUIT && false)
	// {
	// 	printf("HELLOOO");
	// }
	// This signal is triggered by: ctrl + C
	if (signum == SIGINT)
	{
		// Printing out the newline is for a different case, so when just pushing plain ctrl + c, the newline should be omitted.
		// ft_putchar('\n');
		rl_replace_line("", 0);
		rl_done = 1;
	}
}

int	sig_no_response(void)
{
	return (0);
}

void	init_signals(void)
{
	extern int	rl_catch_signals;
	extern int	(*rl_event_hook)(void);

  rl_catch_signals = 0;
	rl_event_hook = sig_no_response;

	signal(SIGCHLD, sighandler);
	signal(SIGQUIT, sighandler);
  signal(SIGINT, sighandler);
}
