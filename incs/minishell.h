//
// Created by Yevheniia ZAVHORODNIA on 12/1/18.
//

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/includes/libft.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/includes/ft_printf.h"
# include <unistd.h>
# include <locale.h>

# define WD_SIZE 1025

typedef struct s_programs {
    char *name;
    void (*program_manager)(char **);
} t_programs;

typedef struct s_stuff {
    char **env;
    char **paths;
    char curr_dir[WD_SIZE];
    char *home;
} t_stuff;

extern t_programs programs[];
extern t_stuff stuff;

void ft_echo(char **args);
void ft_cd(char **args);
void ft_setenv(char **args);
void ft_unsetenv(char **args);
void ft_env(char **args);
void ft_exit(char **args);

char **get_paths();
void search_bin(char *cmd, char **args);
char *convert_env_var(char *var);

#endif
