/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 17:53:17 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/23 17:53:19 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//1. itereer door linkedlist die de input line heeft getokenized
//2. zoeken naar alle tokentype = 0
//3. woord achter de '<' opslaan in een node voor elke tokentype = 0 die je tegenkomt
//4. hiervan een linkedlist maken (ft_lst_addback)

// TODO:
// lst_addback fixen
void	ft_redirections(char *input, t_lexer *lexer)
{
	t_lexer	*tmp;
	char	*str;

	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == 0)
		{
			str = ft_substr(input, tmp->next->index, tmp->next->length);
			if (!str)
				return ;
			tmp->file = (t_file *)ft_lstnew((char *)str);
			tmp->file->infile = str;
			ft_lstadd_back(&lexer, tmp->file);
			// printf("werk: %s\n", tmp->file->infile);
		}
		tmp = tmp->next;
	}
	printf("werk2: %s\n", lexer->file->next->infile);
}

void	parser(char *input, t_lexer *lexer)
{
	ft_redirections(input, lexer);
}

// PARSEN

// Redirect infield(<):
// - Zoekt naar de file die achter “<“ staat en gebruikt dat als input
// - Als we < sla woord achter < op / zelfde voor outfile

// Redirect outfile(>):
// - Maakt een file aan en pleurt de data naar die file toe

// Redirect here_doc(<<):
// - zorgt ervoor dat je prompt krijgt totdat de delimiter wordt geschreven in de prompt. Het argument achter “<<“ is de delimiter.
// - Wanneer << here_doc woorden achter << (dubbele redirection) opslaan.

// Redirect outfile append(>>):
// - Zoekt naar de file die achter “>>” komt en overwrite data die erin staat met de gegeven data in de command line

// Commands:
// - Zorgen ervoor dat de commands worden gegroepeerd indien dat nodig is, bijv bij een “command + optie” en dat vervolgens op te slaan. Dit zorgt ervoor dat je daarna de commands kan executen.
// - Maak lijst van alle opties die komen na een command zodat je die in exec kan pleuren
// -      execve(const char *path, char *const argv[], char *const envp[]);
// *Path is de relatieve pad (/bin/ls) of (${PWD}/bin/ls)
// Const *argv[] = alle opties(dus dubbele array)