//
// Created by Yevheniia ZAVHORODNIA on 12/1/18.
//

#include "../incs/minishell.h"

void ft_env(char **args){
    if (!stuff.env)
        return;
    for (int i = 0; stuff.env[i]; i++) {
        ft_putendl(stuff.env[i]);
    }
};