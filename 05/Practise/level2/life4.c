#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	(void)argc;
	int w = atoi(argv[1]), h = atoi(argv[2]), iter = atoi(argv[3]);
	int board[h][w], next[h][w], x = 0, y = 0, pen = 0;
	char c;
	
	int i = 0;
	while (i < h)
	{
		int j = 0;
		while (j < w)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	
	while (read(0, &c, 1) == 1)
	{
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c === 'd' && x < w - 1)
			x++;
		else if (c == 'x')
			pen = 1;
		if (pen)
			board[y][x] = 1;
	}
	
	int k = 0;
	while (k < iter)
	{
		int i = 0;
		while (i < h)
		{
			int j = 0;
			while (j < w)
			{
				int n = 0;
				int ai = -1;
				while (ai <= 1)
				{
					int aj = -1;
					while (aj <= 1)
					{
						if ((ai || aj) && i + ai >= 0 && i + ai < h && j + aj >= 0 && j + aj < w)
							n += board[i + ai][j + aj];
						aj++;
					}
					ai++;
				}
				next[i][j] = (board[i][j] && (n == 2 || n == 3)) || (!board[i][j] && n == 3);
				j++;
			}
			i++;
		}
	
		int a = 0;
		while (a < h)
		{
			int j = 0;
			while (j < w)
			{
				board[a][j] = next[a][j];
				j++;
			}
			a++;
		}
		k++;
	}
	
	i = 0;
	while (i < h)
	{
		int j = 0;
		while (j < w)
		{
			putchar(board[i][j] ? '0' : ' ');
			j++;
		}
		putchar('\n'); //forgot new line but not the end of the world
		i++;
	}
	return 0;
}
