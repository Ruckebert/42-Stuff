
#include "microshell.h"

int error_msg(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (*arg)
	{
		while (*str)
			write(2, str++, 1);	
	}
	write(2, "\n", 1);
	return (1);
}

int cd(char **argv, int i)
{
	if (i != 2)
		return (error_msg("error:", "fatal"));
	else if (chdir(argv[1]) != 0)
		return (error_msg("error:", "fatal"));
	return (0);
}

int exe(char **argv, char **env, int i)
{
	int fd[2];
	int exit_code = 0;
	int pipe_y = argv[i] && !strcmp(argv[i], "|");

	if (pipe_y && pipe(fd) == -1)
		return (error_msg("error:", "fatal"));
	int child = fork();
	if (child == 0)
	{
		argv[i] = NULL;
		if (pipe_y && dup2(fd[1], 1) == -1)
			return (error_msg("error:", "fatal"));
		if (pipe_y && (close(fd[0]) == -1 || close(fd[1]) == -1))
			return (error_msg("error:", "fatal"));
		execve(*argv, argv, env);
		return (error_msg("error:", "fatal"));
	}
	waitpid(child, &exit_code, 0);
	if (pipe_y && dup2(fd[0], 0) == -1)
		return (error_msg("error:", "fatal"));
	if (pipe_y && (close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error_msg("error:", "fatal"));
	return (WEXITSTATUS(exit_code));
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	int exit_code = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				exit_code = cd(argv, i);
			else
				exit_code = exe(argv, env, i);
		}
	}
	return (exit_code);
}