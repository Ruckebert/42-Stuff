#include <errno.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int count = 0, max_fd = 0;
int ids[65536];
fd_set afds, wfds, rfds;
char *msgs[65536];
char buf_write[1001], buf_read[42];


int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error()
{
	write(2, "fatal error\n", 13);
	exit(1);
}

int create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (max_fd < 0)
		fatal_error();
	FD_SET(max_fd, &afds);
}

void notify(int author, char *stg)
{
	int fd = 0;
	while (fd <= max_fd)
	{
		if (FD_ISSET(fd, &wfds) && fd != author)
			send(fd, stg, strlen(stg), 0);
		fd++;
	}
}

void send_msg(int fd)
{
	char *msg;
	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		notify(fd, buf_write);
		notify(fd, msg);
		free(msg);
	}
}

void accept_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count ++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "Welcome client %d", ids[fd]);
	notify(fd, buf_write);
}

void remove_client(int fd)
{
	sprintf(buf_write, "Client %d has left", ids[fd]);
	notify(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Not enough arguments!\n", 23);
		return 1;
	}

	FD_ZERO(&afds);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT //keeps all the servaddrs info
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(8081); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
	{ //change this to return fatal_error
		fatal_error();
	} 
	if (listen(sockfd, 10) != 0) 
	{ //changed this to retunr fatal error 
		fatal_error();
	}

	while (1)
	{
		rfds = wfds = afds;
		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			fatal_error();
		int fd = 0;
		while (fd <= max_fd)
		{
			if (!FD_ISSET(fd, &wfds))
				continue ;
			if (fd == sockfd)
			{
				socklen_t addr_len = sizeof(servaddr);
				int client = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
				if (client >= 0)
				{
					accept_client(client);
					break ;
				}
			}
			else 
			{
				int read_byt = recv(fd, buf_read, 1000, 0);
				if (read_byt <= 0)
				{
					remove_client(fd);
					break ;
				}
				buf_read[read_byt] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
			}
			fd++;
		}
	}
}