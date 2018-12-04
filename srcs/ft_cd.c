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
	if (!stuff.home)
	{
		ft_printf("HOME %s\n", stuff.home);
		return;
	}
	chdir(stuff.home);
}

void go_back() {

}

//TODO figure out where to handle different errors (no env, invalid $NAME, invalid path, no access (not handled at all for now)

/*
 * function to convert environment variables to their actual values
 */
char *convert_env_var(char *var) {
	int i;
	size_t len;

	char *converted;
	if (ft_strlen(var) == 1)
		return (var);
	if (!stuff.env) // TODO HANDLE
		return (NULL);
	i = 0;
	while (stuff.env[i])
	{
		len = ft_strlen(var) - 1;
		if (!ft_strncmp(var + 1, stuff.env[i], len) && stuff.env[i][len] == '=') //ne kostyl
			return (ft_strdup(stuff.env[i] + len + 1));
		i++;
	}
	return (stuff.home);
}

void change_dir(char *new_dir) {
	if (!new_dir)
		ft_putendl("cd: fatal: stay here guy"); //TODO HANDLE
}

void ft_cd(char **argv)
{
	int argc;
	char *alt_path; //for $

	argc = array_len(argv);
//	ft_printf("ARGC %d", argc); //debug
	if (!argc)
		go_home();
	else if (argc > 1) //TODO: handle cd with 2 args
		ft_putendl("cd: too many arguments");
	else {
		if (!ft_strcmp(argv[0], "-"))
			go_back();
		else if (!ft_strcmp(argv[0], "~"))
			go_home();
		else if (argv[0][0] == '$')
			change_dir(convert_env_var(argv[0]));
		else
			change_dir(argv[0]);
	}
};