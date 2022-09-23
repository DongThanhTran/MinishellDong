/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:37 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/23 14:41:11 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// waarschijnlijk is deze functie niet nodig.
void	update_data(t_lexer *head, t_token_type old, t_token_type new)
{
	t_lexer	*lexer;

	if (head == NULL)
	{
		printf("Linked List not initialized\n");
		return ;
	}
	lexer = head;
	while (lexer != NULL)
	{
		if (lexer->type == old)
		{
			lexer->type = new;
			// printf("old found: %d changed to new %d\n", old, new);
			return ;
		}
		lexer = lexer->next;
	}
	printf("%d does not exist in the list\n", old);
}

void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("index: %d\t lenght: %d\t type: %d\n", head->index, \
				head->length, head->type);
		head = head->next;
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
