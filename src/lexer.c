/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:28 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:40:36 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	set_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	if (ft_strncmp(input, "<<", 3) == 0)
		*type = HERE_DOC;
	else if (ft_strncmp(input, ">>", 3) == 0)
		*type = OUTFILE_APPEND;
	else if (input[pos] == '|')
		*type = PIPE;
	else if (input[pos] == '<')
		*type = INFILE;
	else if (input[pos] == '>')
		*type = OUTFILE;
	else
		*type = COMMAND;
	free(str);
	return (1);
}

static int	ft_wrlength(char *input)
{
	int	i;

	i = 0;
	while (input[i] && (!ft_isspace(input[i]) && special_chars(input[i]) == 0))
	{
		i++;
	}
	return (i);
}

static int	ft_symbol_len(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i]))
	{
		if ((input[i] == '<' && input[i + 1] == '<') || \
		(input[i] == '>' && input[i + 1] == '>'))
			return (2);
		else if (special_chars(input[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	add_to_list(t_lexer **head, int length, int pos, t_token_type type)
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
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (!special_chars(input[i]))
			len = ft_wrlength(&input[i]);
		else
			len = ft_symbol_len(&input[i]);
		if (input[i] == '\"' || input[i] == '\'')
		{
			len = check_quotes(&input[i]) - 1;
			i += 2;
		}
		if (set_type(&type, input, i, len) == 0)
			return (NULL);
		if (add_to_list(&head, len, i, type) == 0)
			return (NULL);
		i += len;
		len = 0;
	}
	print_list(head);
	return (head);
}
