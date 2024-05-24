/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:55:56 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/30 15:25:29 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Core Function 
static char *fill_buffer(int fd, char *line,char  *red_buf)
{
	ssize_t	reader;
	char *temp;

	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		else if (reader == 0)
			break ;
		line[reader] = '\0';
		if (!red_buf)
			red_buf = ft_strdup("");
        temp = ft_strjoin(red_buf, line);
		red_buf = temp;
        if (ft_strchr(line, '\n'))
            break ;
    }
	return (red_buf);
}

//char *set_line(char *line_buffer) this puts the string into a new string
static char *set_line(char *line)
{
	ssize_t	count;
	char	*temp;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == 0 || line[1] == 0)
		return (NULL);
	temp = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (temp == NULL)
		return (NULL);
	line[count] = '\0';
	return(temp);
}

//Get_Next_Line
char	*get_next_line(int fd)
{
	char	*line;
	char	*next_line;
	static char *red_buf;
	static int	counter;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	if (counter == 0)
	{
		red_buf = (char *)malloc(1);
		if (red_buf == NULL)
			return (NULL);
		red_buf[0] = '\0';
		counter++;
	}
	red_buf = fill_buffer(fd, line, red_buf);
	printf("%s", red_buf);
	free(line);
	line = NULL;
	if (!red_buf)
		return (NULL);
	next_line = set_line(red_buf);
	if (!next_line)
		return (NULL);
	return (next_line);
}

//Shitty Main

int main()
{
    int fd = open("example.txt", O_RDONLY);
	printf("%d", fd);
    char *line = get_next_line(fd);

    printf("%s \n", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    free(line);
    close(fd);
    return (0);
}
