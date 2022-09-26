/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:28 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/26 23:02:43 by mlvb          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Need to find a way to handle the malloc of substr
// Strncmp segfaults on NULL
t_token_type	set_type(char *input, int pos, int len)
{
	if (ft_strncmp(ft_substr(input, pos, len), "<<", 2) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(ft_substr(input, pos, len), ">>", 2) == 0)
		return (OUTFILE_APPEND);
	else if (input[pos] == '|')
		return (PIPE);
	else if (input[pos] == '<')
		return (INFILE);
	else if (input[pos] == '>')
		return (OUTFILE);
	else
		return (COMMAND);
}

static int	ft_wrlength(char *input)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	while (input[i + count] && !ft_isspace(input[i + count]))
		count++;
	return (count);
}

int	add_to_list(t_lexer **head, int length, int pos, t_token_type type)
{
	t_lexer	*tmp;
	t_lexer	*new;

	new = ft_calloc(sizeof(t_lexer), 1);
	if (!new)
		return (0);
	new->length = length;
	new->index = pos;
	new->type = type;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

t_lexer	*ft_snorlexer(char *input)
{
	t_lexer				*head;
	int					i;
	int					len;
	t_token_type		type;

	head = NULL;
	i = 0;
	len = 0;
	while (input[i])
	{
		len = ft_wrlength(&input[i]);
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i] == '\"' || input[i] == '\'')
		{
			len = check_quotes(&input[i]);
			i++;
		}
		type = set_type(input, i, len);
		add_to_list(&head, len, i, type);
		i += len;
		i++;
		len = 0;
	}
	return (head);
}

// kut "homo tieten" en andere "din gen :)"

// < infile grep "tieten" | je moer > out