#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("****** 1.play ***********\n");
	printf("****** 0.exit ***********\n");
	printf("*************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Intboard(board, ROW, COL);
	Display(board, ROW, COL);

	//下棋
	while (1)
	{
		Player(board, ROW, COL);//玩家下棋
		Display(board, ROW, COL);
		ret = Iswin(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		Computer(board, ROW, COL);//电脑下棋
		Display(board, ROW, COL);
		ret = Iswin(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	Display(board, ROW, COL);

}

int main()
{
	//游戏菜单
	menu();
	srand((signed int)time(NULL));
	int input = 0;
	do
	{
		//1.选择开始游戏；0.退出游戏
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//游戏的实现函数
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}