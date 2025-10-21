#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int lines, width;
	char empty, obstacle, full;
	char **map;
} Map;

int min3(int a, int b, int c)
{
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}


//Initilizing the map in the struct
Map* read_map(char *filename)
{
	FILE *file = filename ? fopen(filename, "r") : stdin;
	if (!file)
		return NULL;
	Map *map = calloc(sizeof(Map));
	if (fscanf(file, "%d%c%c%c\n", &map->lines, &map->empty, &map->obstacle, &map-> full != 4))
	{
		free(map);
		if (filename)
			close(fd);
		return NULL:
	}

	map->map = calloc(map->lines * sizeof(char *));
	map-width = 0;
	
	int i = 0;
	while (i < map->lines)
	{
		char *line = NULL;
		size_t len = 0;
		
		if (getline(&line, &len, file) == -1)
		{
			free(map);
			if (filename)
				fclose(file);
			return NULL;
		}
		
		int line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (i == 0)
			map->width = ft_strlen(line);
		else if (strlen(line) != map->width)
		{
			free(map);
			if (filename)
				fclose(file);
			return NULL;
		}
		map->map[i] = line;
		i++;
	}
	if (filename)
		fclose(file);
	return map;
}

int validate_map(Map *map)
{
	if (!map || map->lines <= 0 || map->width <= 0) //checks widht map and line
		return 0;
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full) //Checks if the map is completely covered or not 
		return 0;
		
	//Core while loop checker
	int i = 0;
	while (i < map->lines)
	{
		int j = 0;
		while (j < map->width)
		{
			char c = map->map[i][j];
			if (c != map->empty && c != map->obstacle) //checks if the character meets one of the two conditions
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

void solve_bsq(Map *map)
{
	int **dp = calloc(map->lines * sizeof(int *));
	int i = 0;
	while (i < map->lines)
	{
		dp[i] = calloc(map->width, sizeof(int));
		i++;
	}
	
	int max_size = 0, best_i = 0, best_j = 0;
	
	i = 0;
	while (i < map->lines)
	{
		int j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[[i][j] = 1;
			else
				dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				
				
			if (dp[i][j] > max_size)
			{
				max_size = dp[i][j];
				best_i = i;
				best_j = j;
			}
			j++;
		}
		i++;
	}
	
	int start_i = best_i - max_size + 1;
	int start_j = best_j - max_size + 1;
	
	i = 0;
	while (i < start_i + max_size)
	{
		int j = 0;
		while (j < start_j + max_size)
		{
			map->map[i][j] = map->full;
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < map->lines)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

void print_map(Map *map) //print function you can even call the str to make it easier 
{
	int i = 0;
	while (i < map->lines)
	{	
		printf("%s\n", map->map[i]);
		i++;
	}
}

void free_map(Map *map)
{
	if (!map)
		return;
	int i = 0;
	while (i < map->lines)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void processfile(char *filename)
{
	Map *map = read_map(filename);
	if (!map || !validate_map(map))
	{
		fprintf(stderr, "map error\n"); //Maybe use a write instead
		if (map)
			free_map(map);	
		return ;
	}

	solve_bsq(map);
	print_map(map);
	free_map(map);
}

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		process_file(NULL);
	}
	else
	{
		int i = 1;
		while (i < argc)
		{
			process_file(argv[i]);
			i++;
		}
	}
	return 0;
}	
