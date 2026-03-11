#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_client
{
    int id;
    int fd;
    char *buffer;

} t_client ;

t_client clients[1024];
fd_set read_set, write_set, current;
char send_buffer[400000], recv_buffer[1024];
int maxfd, gid = 0;

void error(char *str)
{
    for (int i = 0; i < 1024; i++)
    {
        free(clients[i].buffer);
        if (clients[i].id != -1)
            close(clients[i].fd);
    }
    write(2, str, strlen(str));
    write(2, "\n", 1);
    exit(1);
}

void    send_all(int fd_sender)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, &write_set) && fd != fd_sender)
        {
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
                error("Fatal error");
        }
    }
}

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


int main(int argc, char **argv) 
{

    for (int i = 0; i < 1024; i++)
    {
        clients[i].id = -1;
        clients[i].buffer = NULL;
    }
    if (argc != 2)
	{
        error("Wrong number of arguments");
		return 1;
	}
	int	sockfd = 0, connfd = 0;
	struct sockaddr_in servaddr;

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		error("Fatal error");
	} 
	bzero(&servaddr, sizeof(servaddr));
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        close(sockfd), error("Fatal error");
	} 
	if (listen(sockfd, 10) != 0) {
		close(sockfd), error("Fatal error");
	}

	FD_ZERO(&current);
    FD_SET(sockfd, &current);
    maxfd = sockfd;
    while (1)
    {
        read_set = write_set = current;
        if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
            continue;
        for (int fd = 0; fd <= maxfd; fd++)
        {
            if (FD_ISSET(fd, &read_set))
            {
                if (fd == sockfd)
                {
                    connfd = accept(sockfd, NULL, NULL);
                    if (connfd == -1)
                        close(sockfd), error("Fatal error");
                    if (connfd > maxfd)
                        maxfd = connfd;
                    FD_SET(connfd, &current);
                    clients[connfd].id = gid++;
                    clients[connfd].fd = connfd;
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[connfd].id);
                    send_all(connfd);
                    break;
                }
                else
                {
                    int res = recv(fd, recv_buffer, 1023, 0);
                    if (res <= 0)
                    {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_all(fd);
                        FD_CLR(fd, &current);
                        close(fd);
                        clients[fd].id = -1;
                        free(clients[fd].buffer);
                        clients[fd].buffer = NULL;
                    }
                    else
                    {
                        recv_buffer[res] = 0;
                        clients[fd].buffer = str_join(clients[fd].buffer, recv_buffer);
                        if (!clients[fd].buffer)
                            close(sockfd), error("Fatal error");
                        while (1)
                        {
                            char *message = NULL;
                            int retval = extract_message(&clients[fd].buffer, &message);
                            if (retval == -1)
                                close(sockfd), error("Fatal error");
                            if (retval == 0)
                                break ;
                            sprintf(send_buffer, "client %d: %s", clients[fd].id, message);
                            send_all(fd);
                            free(message);
                        }
                    }
                }
            }
        }
	}
}