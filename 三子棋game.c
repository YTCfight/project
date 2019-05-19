#include"game.h"
void intit(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void shezhiqipan(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<row - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void wanjiawan(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家走:>\n");
	while (1)
	{
		scanf("%d%d", &i, &j);
		if (i <= row && i >= 1 && j <= col && j >= 1)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("该坐标被占用\n");
		}
		else
			printf("输入错误，请重新输入\n");
	}
}
void diannaozou(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		if (board[i][j] == ' ')
			return 0;
	}
	return 1;
}
char panduan(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&board[0][0] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[2][0];
	if (isfull(board, row, col) == 1)
		return 'Q';
	return 'C';
}
