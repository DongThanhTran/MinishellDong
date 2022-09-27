
#include "minishell.h"


/*
  This function prints out the current working directory.
  For now I went with the env struct, but thinking of putting the pwd straight into a var
*/

void  pwd(t_env *env)
{
  ft_putendl_fd(env->value, 1);
}