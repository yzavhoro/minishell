//
// Created by Yevheniia ZAVHORODNIA on 12/1/18.
//

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_programs {
    char *name;
    void (*program_manager)(char **);
} t_programs;

extern t_programs programs[];

void ft_echo(char **args);
void ft_cd(char **args);
void ft_setenv(char **args);
void ft_unsetenv(char **args);
void ft_env(char **args);
void ft_exit(char **args);

#endif
