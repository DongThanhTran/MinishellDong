/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:05 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/23 17:54:00 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define MINISHELL_H
# define SPECIAL_CHAR "$|<>\'\""

typedef enum e_token_type {
	INFILE,
	OUTFILE,
	OUTFILE_APPEND,
	HERE_DOC,
	ARGUMENT,
	PIPE,
	COMMAND,
}	t_token_type;

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_file {
	char			*infile;
	char			*outfile;
	char			*heredoc;
	struct s_file	*next;
}	t_file;

typedef struct s_lexer {
	t_token_type	type;
	int				length;
	int				index;
	t_file			*file;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_shell
{
	t_env	*env;
	int		fd_in;
	int		fd_out;
	t_lexer	*lexer;
}	t_shell;

// Envp parser for storing the keys and values of envp
void	parse_env(char *envp[]);

// Lexer Functions
void	ft_snorlexer(char *input);
int		check_quotes(char *input);
void	post_processing(char *input, t_lexer *lexer);

// Util Functions
int		special_chars(char c);
void	update_data(t_lexer *head, t_token_type old, t_token_type new);

// List Functions
void	print_list(t_lexer *head);

#endif