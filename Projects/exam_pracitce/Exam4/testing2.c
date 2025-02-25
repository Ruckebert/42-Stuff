
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

//Error Msg
void	error_msg(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
	{
		while (*arg)
			write(2, arg++, 1);
	}
	write(1, "\n", 1);
}

int	executor(char **argv, char **env, int i)
{
	int fd[2];
	int exit_code = 0;
	int pipe_y = argv[i] && !strcmp(argv[i], "|");

	if (pipe_y && pipe(fd) == -1)
		return (error_msg("error:", "fatal"), 1);
	int childid = fork();
	if (childid == 0)
	{
		argv[i] = NULL;
		if (pipe_y && dup2(fd[1], 1) == -1)
			return (error_msg("error:", "fatal"), 1);
		if (pipe_y && (close(fd[0]) == -1 || close(fd[1]) == -1))
			return (error_msg("error:", "fatal"), 1);
		execve(*argv, argv, env);
		return (error_msg("error:", "fatal"), 1);
	}
	waitpid(childid, &exit_code, 0);
	if (pipe_y && dup2(fd[0], 1) == -1)
		return (error_msg("error:", "fatal"), 1);
	if (pipe_y && (close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error_msg("error:", "fatal"), 1);
	return (WEXITSTATUS(exit_code));
}

int cd(int i, char **argv)
{
	if (i != 2)
		return (error_msg("error:", "fatal"), 1);
	else if (chdir(argv[1]) != 0)
		return (error_msg("error:", "fatal"), 1);
	return (0);
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
				exit_code = cd(i, argv);
			else
				exit_code = executor(argv, env, i);
		}
	}
	return (exit_code);
}