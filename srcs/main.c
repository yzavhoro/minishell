#include "../incs/minishell.h"

t_programs programs[] = {{"echo", ft_echo},
                         {"cd", ft_cd},
                         {"setenv", ft_setenv},
                         {"unsetenv", ft_unsetenv},
                         {"env", ft_env},
                         {"exit", ft_exit}};
t_stuff stuff;
void ft_echo(char **args) {
    ft_putendl("program not realized yet, but here's some flowers 4 u:");
    ft_printf("🌸🌸🌸🌸🌸🌸\n");
};
void ft_cd(char **args) {
    ft_putendl("no");
};
void ft_setenv(char **args){
    ft_putendl("no");
};
void ft_unsetenv(char **args){
    ft_putendl("no");
};

void ft_exit(char **args){
//    system("leaks jen9shell");
    exit(0);
};

void display_prompt() {
    write(1, "jen9shell> ", 11);
}

void arrdel(char **arr) {
    for(int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

void manage_command(char *cmd) {
    char **tokens = ft_strsplit(cmd, ' ');
    if (!tokens || !tokens[0])
        return;
    int i;
    for (i = 0; i < 6; i++) { //TODO remove this horrible 6 to sth normal'noe
        if (!ft_strcmp(tokens[0], programs[i].name)) {
            programs[i].program_manager(++tokens);
            arrdel(--tokens);
            break;
        }
    }
    if (i == 6) {
        arrdel(tokens);
        ft_printf("jen9shell: command not found: %s\n", tokens[0]);
    }
}

int main(int argc, char **argv, char **env) {
    char *cmd;
    stuff.env = env;
    setlocale(LC_ALL, "");
    int i = 6;
    while (i--) {
        display_prompt();
        get_next_line(0, &cmd);
        manage_command(cmd);
        free(cmd);
    }
//    system("leaks jen9shell");
    return 0;
}