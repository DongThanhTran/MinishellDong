/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 17:53:17 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:43:18 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_redirections(char *input, t_lexer *lexer)
{
	t_infile	*in;
	t_outfile	*out;

	in = NULL;
	out = NULL;
	while (lexer != NULL)
	{
		check_files(input, lexer, in, out);
		lexer = lexer->next;
	}
}

void	ft_parser(char *input, t_lexer *lexer)
{
	ft_redirections(input, lexer);
	return ;
}
