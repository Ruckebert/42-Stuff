#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	int w = atoi(argv[1]), h = atoi(argv[2]), iter = atoi(argv[3]);
	int board[w][h], next[w][h], x = 0, y = 0, pen = 0;//forgot to add next
	char c;
	
	//Assigning all values in the grid to 0
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

	//draw
	while (read(0, &c, 1) == 1)
	{
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h -1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x  < w - 1)
			x++;
		else if (c == 'x')
			pen == 1;
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
				//From this part downwards checks whether a near by cell is alive or not 
				int num = 0;
				int ai = -1;
				while (ai <= 1)
				{
					int aj = -1;
					while (aj <= 1)
					{
						if ((ai || aj) && i + ai >= 0 && i + ai < h && j + aj >= 0 && j + aj < w)
							n += board[i+ai][j+aj];
						aj++;
					}
					ai++;
				}
				next[i][j] = (board[i][j] && (n == 2 || n == 3) || (!board[i][j] && n == 3))
				j++;
			}
			i++;
		}
		
		//final set before printing check if the values are truly alive
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



	//prints
	i = 0;
	while (i < h)
	{
		int j = 0;
		while (j < w)
		{
			putchar(board[i][j] ? '0' : ' ');
			j++;
		}
		i++;
	}


	return (0);
}
