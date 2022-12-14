/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   files.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 14:39:21 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:39:25 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	add_to_infile_list(t_infile **head, char *infile)
{
	t_infile	*tmp;
	t_infile	*new;

	new = ft_calloc(sizeof(t_infile), 1);
	if (!new)
		return (0);
	new->infile = infile;
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

static int	add_to_outfile_list(t_outfile **head, char *infile)
{
	t_outfile	*tmp;
	t_outfile	*new;

	new = ft_calloc(sizeof(t_outfile), 1);
	if (!new)
		return (0);
	new->outfile = infile;
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

int	check_files(char *input, t_lexer *lexer, t_infile *in, t_outfile *out)
{
	char	*file;

	if (lexer->type == 0)
	{
		file = ft_substr(input, lexer->next->index, lexer->next->length);
		if (add_to_infile_list(&in, file) == 0)
			return (0);
		free(file);
	}
	if (lexer->type == 1)
	{
		file = ft_substr(input, lexer->next->index, lexer->next->length);
		if (add_to_outfile_list(&out, file) == 0)
			return (0);
		free(file);
	}
	print_file_list(in, out);
	return (1);
}