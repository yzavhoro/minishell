//
// Created by Yevheniia ZAVHORODNIA on 12/3/18.
//

#include "../incs/minishell.h"

int array_len(char ** array) {
	int i;

	if (!array)
		return (-1);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

void go_home() {

}

void go_back() {

}

char *convert_env_var(char *var) {
	if (ft_strlen(var) == 1)
		return (var);
	
}

void ft_cd(char **argv)
{
	int argc;
	char *alt_path; //for $

	argc = array_len(argv);
	ft_printf("ARGC %d", argc); //debug
	if (!argc)
		go_home();
	else if (argc > 1) {//TODO handle cd with 2 args
		if (!ft_strcmp(argv[0], "-"))
			go_back();
		else if ()
	}

};