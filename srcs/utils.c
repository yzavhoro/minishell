//
// Created by Yevheniia ZAVHORODNIA on 12/2/18.
//

#include <dirent.h>
#include "../incs/minishell.h"

char **get_paths() {
	int i;

	i = 0;
    while (stuff.env[i] && ft_strncmp(stuff.env[i], "PATH=", 5))
        i++;
    if (!stuff.env[i]) {
        return NULL;
    }
    return (ft_strsplit(stuff.env[i] + 5, ':'));
}

void exec_bin(char *file, char **args) {
    int status;

    status = fork();
    if (status == 0) {
        execve(file, args, stuff.env);
        exit(0);
    } else {
    	wait(&status);
    }
}

int find_matching(char *cmd) {
	int				i;
	DIR				*dirp;
	struct dirent	*dp;

	i = 0;
	while (stuff.paths[i]) {
		dirp = opendir(stuff.paths[i]);
		while ((dp = readdir(dirp)) != NULL) {
			if (!ft_strcmp(dp->d_name, cmd)) {
				return (i);
			}
		}
		(void)closedir(dirp);
		i++;
	}
	return (-1);
}

void search_bin(char *cmd, char **args) {
    int				i;
    DIR				*dirp;
    struct dirent	*dp;

    i = find_matching(cmd);
	if (i == -1)
		ft_printf("jen9shell: command not found: %s\n", cmd);
	else
		exec_bin(ft_strjoin(ft_strjoin(stuff.paths[i], "/"), cmd), args);
}