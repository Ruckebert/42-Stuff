/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:03:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/17 10:17:17 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

//Functions for project
//fork function is very important --> pid_t fork(void);
//int access(const cahr *pathname, int mode) --> checks whether the file is accessable
//int dup2(int oldfile, int newfile) -- > makes newfile the copy of oldfile 
//Pipe function is import --> int pipe(int pipefd[fd])
//fd can be either 0 or 1 --> 1 transfers its data into 0 (I think?)
//
//
//Need a function for the child process and parent process? (Defiently need it for the childi)
//Execve executes the command.
//Cmda and cmdb must be splited this is most likely for the cause of executing the pipes and the child
// Child process opens the infile and the parent process opens the outfile

//Maybe before executing path finder check whether its accessable or not
//Make something to also check whether or not a path exists
//Remove the two form the pathfinder

void path_finder2(char **envp, char *argv)
{ //Path_finder works will need to be worked on before publish
	char **store;
	char **cmd;
	char *comm;
	int i;

	i = 0;
	while(ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	store = ft_split(envp[i] + 5, ':'); //Exit if split fails
	cmd = ft_split(argv, ' ');
	i = 0;
	while (store[i])
	{
		comm = ft_strjoin(store[i], "//");
		comm = ft_strjoin(comm, cmd[0]); //Change the varaible in comm to something else
		execve(comm, cmd, envp);
		free(comm);
		i++;
	}
}

//Check error handling
void child(char *argv[],char **envp, int *fd) //Creates a Child 
{
	int	fdin;

	close(fd[0]);
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
	{
		close(fd[1]);
		perror("Infile can not be opened");
		exit(1);
	} //dup2 closes the stdinput and file 1 becomes the new stdin
	dup2(fdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	path_finder2(envp, argv[2]);
}

//The parent process follows the same format of the child process
//Change the parent process as the inputs are wrong 
//the parent process must also execute a command
void parent(char *argv[],char **envp, int *fd)
{
	int	fdout;

	close(fd[1]);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_RDONLY, 0777);
	if (fdout == -1)
	{
		close(fd[0]);
		perror("Infile can not be opened");
		exit(1);
	}
	dup2(fdout, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	path_finder2(envp, argv[3]);
}

void error_handler()
{
	perror("A Error Has occured");
	exit(1);
}

//This function is useless but its nice to look at
int file_read(char *str) //Simple function that open and closes the file
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd == -1)
		return (-1);
	printf("%d", fd);
	close(fd);
	return (0);
}


//Main
int main(int argc, char *argv[],char **envp)
{
	int fd[2];
	int childid;

	if (argv[1] == NULL || argc == 0) // maybe remove this
		return (0);
	if (argc == 5)
	{ 
		if (access(argv[1], O_RDONLY) == 0)
		{
			if (pipe(fd) == -1)
			{
				perror("Pipe Failure");
				return (0);
			}
		}
		else
		{
			perror("Infile is not accessable");
			return (0);
		}
		childid = fork();
		if (childid == -1)
		{
			perror("Error While Forking");
			return (0);
		}
		if (childid == 0)
			child(argv, envp, fd);
		else
		{
			wait(NULL); 
			parent(argv, envp, fd);
		}
	}
	else
		perror("Error: Bad Arguments and wrong format");
	return (0);
}
// Notes for main //
// Pipe the fd??
// fork the pid1 which is under the structure of pid_t
// pid1 is most likely a struct with int as the varaible 
// if the fork fails return error which makes sense
// if the fork = 0 continue with the child procerss which makes sense since the id of the child will always be zero
// waitpid the pid1
// execute the parent process.

//Add an envp checker