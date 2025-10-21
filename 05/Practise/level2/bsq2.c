#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int lines, width;
	char empty, obstacle, full;
	char *map;

} Map;

int min2(int a, int b, int c)
{	//Really large if else
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

Map* read_map(char *filename)
{
	FILE *file = filename ? fopen(filename, "r") : stdin;
	if (!file)
		return NULL;
	Map *map = calloc(sizeof(Map));
	if (fscanf(file, "%d%c%c%c\n", &map->lines, &map->empty, &map->obstacle, &map->full != 4))
	{	//cant this be in its own function and just call the function
		free(map);
		if (filename)
			close(fd);
		return NULL;
	}
	
	map->map = calloc(map->lines * sizeof(char *));
	map->width = 0;
	
	int i = 0;
	while (i < map->lines)
	{
		char *line = NULL;
		size_t len = 0;
	
		if (getline(&line, &len, file) == -1)
		{
			free(map);
			if (filename)
				close(fd);
			return NULL;
		}
		
		int line_len = strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (i == 0) //get the width of the first line
			map->width = strlen(line);
		else if (strlen(line) != map->width)
		{
			free(map);
			if (filename)
				close(fd);
			return NULL;			
		}
		map->map[i] = line;
		i++;
	}
	if (filename)
		fclose(file);
	return map;
}


int valdiate_map(Map *map)
{
	if (!map || map->lines <= 0 || map->width <= 0)
		return 0;
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return 0;
	int i = 0;
	while (i < map->lines)
	{
		int j = 0;
		while (j < map->width)
		{
			char c = map->map[i][j];
			if (c != map->empty && c != map->obstacle)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
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
	while (i < map_lines)
	{
		int j = 0;
		while (j < map->width)
		{
		
		
			j++;
		}
		i++;
	}
}
