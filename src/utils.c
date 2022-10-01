/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:37 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/26 17:25:18 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// deze functie kan er bij het inleveren van het project eruit
void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("index: %d\t lenght: %d\t type: %d\n", head->index, \
				head->length, head->type);
		head = head->next;
	}
}

// deze functie kan er bij het inleveren van het project eruit
void	print_file_list(t_infile *in_head, t_outfile *out_head)
{
	while (in_head != NULL)
	{
		printf("the infile: %s\n", in_head->infile);
		in_head = in_head->next;
	}
	while (out_head)
	{
		printf("the outfile: %s\n", out_head->outfile);
		out_head = out_head->next;
	}
}

int	special_chars(char c)
{
	int	j;

	j = 0;
	while (SPECIAL_CHAR[j])
	{
		if (c == SPECIAL_CHAR[j])
			return (1);
		j++;
	}
	return (0);
}