#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int count = 0, max_fd = 0;
char *msgs[65680];
int ids[65680];
fd_set afds, wfds, rfds;
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
	return max_fd;
}

void notify_others(int author, char *str)
{
	int fd = 0;
	while (fd <= max_fd)
	{
		if (FD_ISSET(fd, &wfds) && author != fd)
			send(fd, str, strlen(str), 0);
		fd++;
	}
}

void create_user(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "welcome client %d", ids[fd]);
	notify_others(fd, buf_write);
}

void remove_user(int fd)
{
	sprintf(buf_write, "client %d has left", ids[fd]);
	notify_others(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}

void send_msg(int fd)
{
	char *msg;
	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		notify_others(fd, buf_write);
		notify_others(fd,msg);
		free(msg);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "not enough arguments\n", 22);
		return 1;
	}
	
	FD_ZERO(&afds);
	struct sockaddr_in servaddr;
	int sockfd = create_socket();

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT //keeps all the servaddrs info
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
	{ //change this to return fatal_error
		fatal_error();
	} 
	else
		printf("Socket successfully binded..\n");
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
			if (!FD_ISSET(fd, &rfds))
				continue ;
			if (fd == sockfd)
			{
				socklen_t addr_len = sizeof(servaddr);
				int client = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
				if (client >= 0)
				{
					create_user(client);
					break ;
				}
			}
			else 
			{
				int read_byt = recv(fd, buf_read, 1000, 0);
				if (read_byt <= 0)
				{
					remove_user(fd);
					break ;
				}
				buf_read[read_byt] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
			}
			fd++;
		}
	}
	return 0;
}