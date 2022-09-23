/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 13:30:15 by dtran         #+#    #+#                 */
/*   Updated: 2022/09/23 13:30:16 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_env(char *envp[])
{
	t_env	*head;
	t_env	*type;
	int		i;
	char	**split_envp;

	type = ft_calloc(sizeof(t_env), 1);
	if (!type)
		return ;
	head = type;
	i = 0;
	while (envp[i])
	{
		split_envp = ft_split(envp[i], '=');
		type->key = split_envp[0];
		type->value = split_envp[1];
		if (type->value && type->key)
		{
			type->next = ft_calloc(sizeof(t_env), 1);
			type = type->next;
		}
		i++;
	}
}
