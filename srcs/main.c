#include "../incs/minishell.h"
#include <unistd.h>

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
        if (!stuff.paths)
            ft_putendl("jen9shell: fatal: no PATH");
        else
            search_bin(tokens[0], tokens);
        arrdel(tokens);
    }
}

int main(int argc, char **argv, char **env) {
    char *cmd;
    stuff.env = env;
    stuff.paths = get_paths();
    stuff.home = convert_env_var("$HOME");
    getcwd(stuff.curr_dir, WD_SIZE);
    setlocale(LC_ALL, "");
    while (1) {
        display_prompt();
        get_next_line(0, &cmd);
        manage_command(cmd);
        free(cmd);
    }
//        int status = fork();
//
//        if (status == 0)
//        {
//            execve(ft_strjoin(ft_strjoin(stuff.paths[i], "/"), cmd), args, stuff.env);
//            exit(0);
//        }
//        else
//        {
//            int return_status = wait(status);
//            WEXITSTATUS(return_status);
//        }



//    char *args_ls[] = {"-l", "/", NULL};
//    execve("/bin/ls", args_ls, env);
//    system("leaks jen9shell");
    return 0;
}