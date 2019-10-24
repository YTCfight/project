#include"game.h"
void menu()
{
	printf("******************\n");
	printf("**  0.   exit  ***\n");
	printf("**  1.   play  ***\n");
	printf("******************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//打印棋盘
	Display(show, ROW, COL);
	//布雷
	Setmine(mine, ROW, COL);
	//Display(mine, ROW, COL);
	//排雷
	Findlei(mine, show, ROW, COL);
}





void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
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
		}
	} while (input);
}


int main()
{
	test();
	system("pause");
	return 0;
}
