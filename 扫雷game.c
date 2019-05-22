#include"game.h"
void Initboard(char board[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}
void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=  col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = EASY;
	while (count)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		
			if (mine[i][j] == '0')
			{
				mine[i][j] = '1';
				count--;
			}
	}
}
int count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x - 1][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void RmoveMine(char mine[ROWS][COLS], int x, int y)//第一次踩雷 移走
{
	mine[x][y] = '0';
	count(mine, x, y);
	while (1)
	{
		int	x1 = rand() % (ROW)+1;
		int	y1 = rand() % (COL)+1;
		if (mine[x1][y1] != '1' && ((x1 != x) && (y1 != y)))
		{
			mine[x1][y1] = '1';
			break;
		}
	}
}
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//展开函数
{
	if ((x >= 1) && (y >= 1) && (x <= ROW) && (y <= COL))
	{
		if (count(mine, x, y) == 0)  //周围没有雷
		{
			show[x][y] = ' ';    //置为空白
			if (show[x - 1][y - 1] == '*')
			{
				Expand(mine, show, x - 1, y - 1);
			}
			if (show[x - 1][y] == '*')
			{
				Expand(mine, show, x - 1, y);
			}
			if (show[x - 1][y + 1] == '*')
			{
				Expand(mine, show, x - 1, y + 1);
			}
			if (show[x][y + 1] == '*')
			{
				Expand(mine, show, x, y + 1);
			}
			if (show[x + 1][y + 1] == '*')
			{
				Expand(mine, show, x + 1, y + 1);
			}
			if (show[x + 1][y] == '*')
			{
				Expand(mine, show, x + 1, y);
			}
			if (show[x + 1][y - 1] == '*')
			{
				Expand(mine, show, x + 1, y - 1);
			}
			if (show[x][y - 1] == '*')
			{
				Expand(mine, show, x, y - 1);
			}
		}
	}
}

void Findlei(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	int clear = 0;
	int minecount = 0;
		while (clear < (ROW)*(COL)-EASY)
		{
			scanf("%d%d", &x, &y);
			if (mine[x][y] == '1')
			{
				if (clear == 0) //第一次踩雷移走
				{
					RmoveMine(mine, x, y);
					Display(mine, ROWS, COLS);
					printf("\n");
					minecount = count(mine, x, y);
					if (minecount == 0)
					{
						show[x][y] = ' ';
						clear++;
						Expand(mine, show, x, y);
						Display(show, ROWS, COLS);
					}
					else
					{
						show[x][y] = minecount + '0';
						Display(show, ROWS, COLS);
					}
				}
				else
				{
					printf("很遗憾，你被炸死了！\n");
					Display(mine, ROWS, COLS);
					break;
				}
			}
			else if (mine[x][y] != '1')
			{
				minecount = count(mine, x, y);
				if (minecount == 0)
				{
					show[x][y] = ' ';
				}
				else
				{
					show[x][y] = minecount + '0';
				}
				clear++;
				Expand(mine, show, x, y);
				Display(show, ROWS, COLS);
			}
			if (clear == (ROW)*(COL)-EASY)
			{
				printf("扫雷成功\n");
			}
		}
}
