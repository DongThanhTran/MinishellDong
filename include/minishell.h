/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:05 by dtran         #+#    #+#                 */
/*   Updated: 2022/10/01 14:48:59 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SPECIAL_CHAR "$|<>\"\'"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

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

typedef struct s_infile {
	char			*infile;
	char			*heredick;
	struct s_infile	*next;
}	t_infile;

typedef struct s_outfile
{
	char				*outfile;
	char				*out_append;
	struct s_outfile	*next;
}	t_outfile;

typedef struct s_lexer {
	t_token_type		type;
	int					length;
	int					index;
	struct s_infile		*in;
	struct s_outfile	*out;
	struct s_lexer		*next;
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
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(char *input);

// Parser
void	ft_parser(char *input, t_lexer *lexer);
int		check_files(char *input, t_lexer *lexer, t_infile *in, t_outfile *out);

// Util Functions
int		special_chars(char c);
void	print_list(t_lexer *head);
void	print_file_list(t_infile *in_head, t_outfile *out_head);

// Signal Functions
void	init_signals(void);

#endif
