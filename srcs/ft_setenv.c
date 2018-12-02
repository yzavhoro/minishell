//
// Created by Yevheniia ZAVHORODNIA on 12/2/18.
//
#include "../incs/minishell.h"

void ft_setenv(char **args){
    if (!*args) {
        ft_putendl("usage: setenv NAME=value");
        return;
    }

};