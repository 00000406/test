#include "game.h"

void Intboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] =' ';
		}
	}
}

void Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)//行数
	{
		for (j = 0;j < col;j++)//列数
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)//列数
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//坐标合理判断
		if (x >=1 && x <= row && y>=1 && y <= col)
		{
			if (board[x - 1][y - 1] ==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用\n");
			}
		}
		else
		{
			printf("坐标不在范围内,请重新输入\n");
		}
	}
}

void Computer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] ==' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满了返回0
			}
			
		}
	}
	return 1;//满返回1
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	if (Isfull(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}
