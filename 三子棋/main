#include"game.h"
void menu()
{
	printf("******************\n");
	printf("*****0.   exit****\n");
	printf("******1. play******\n");
	printf("******************\n");
}
void game()
{
	char ret = { 0 };
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	intit(board, ROW, COL);
	shezhiqipan(board, ROW, COL);
	while (1)
	{
		wanjiawan(board, ROW, COL);
		shezhiqipan(board, ROW, COL);
		ret = panduan(board, ROW, COL);
		if (ret != 'C')
			break;
		diannaozou(board, ROW, COL);
		shezhiqipan(board, ROW, COL);
		ret = panduan(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'Q')
		printf("平局\n");
	else if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢");


}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("进入游戏\n");
			game();
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
