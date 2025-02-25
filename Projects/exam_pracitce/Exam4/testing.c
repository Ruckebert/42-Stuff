/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:39:29 by aruckenb          #+#    #+#             */
/*   Updated: 2025/02/14 13:52:14 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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
	write(2, "\n", 1);
}

//Executor
int	executor(char **argv, char **env, int i)
{
	int fd[2];
	int	exit_code;
	int	pipe_y = argv[i] && !strcmp(argv[i], "|");

	if (pipe_y && pipe(fd) == -1)
		return (error_msg("error:", "fatal"), 1);
	int childid = fork();
	if (!childid)
	{
		argv[i] = 0;
		if (pipe_y && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)) //Duping Stdin
			return (error_msg("error:", "fatal"), 1);
		execve(*argv, argv, env); //EXECUTIONNNNN
		return (error_msg("error:", "execution"), 1);
	}
	waitpid(childid, &exit_code, 0);
	if (pipe_y && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)) //Duping stdout
			return (error_msg("error:", "fatal"), 1);
	return (WEXITSTATUS(exit_code));
} 

//CD
int cd(int i, char **argv)
{
	if (i != 2)
		return (error_msg("error:", "cd: bad arguments"), 1);
	else if (chdir(argv[1]) != 0)
		return (error_msg("error:", "cd: no directory"), 1);
	return (0);
}

//Main
int main(int argc, char **argv, char **env)
{
	int i = 0;
	int exit_code = 0;
	if (argc > 1)
	{
		while(argv[i] && argv[++i])
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

int main2(int argc, char **argv, char **env)
{
	int i = 0;
	int exit_code = 0;
	if (argc > 2)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && argv[++i])
				i++;
			if (!strcmp(*argv, "cd"))
				exit_code = cd(i, argv);
			else
				exit_code = executor(argv, env , i);
		}
		
	}
	return (exit_code);
}
