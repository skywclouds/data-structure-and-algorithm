/*
骑士周游问题
Author:Henry Wang
Date:2021-9-7
*/

#include <iostream>

using namespace std;

int chess[8][8];
int tag = 1;

/*将马移动一步*/
int next(int* x, int* y, int dir);
/*主算法*/
int horsetravel(int x, int y, int tag);

int main()
{
	if (!horsetravel(2, 0, 1))
		cout << "failed." << endl;
}

int next(int* x, int* y, int dir)
{
	switch (dir)
	{
	case 0:
		if (*x + 2 < 8 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 1:
		if (*x + 2 < 8 && *y + 1 < 8 && chess[*x + 2][*y + 1] == 0)
		{
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 2:
		if (*x + 1 < 8 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	case 3:
		if (*x + 1 < 8 && *y + 2 < 8 && chess[*x + 1][*y + 2] == 0)
		{
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	case 4:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 5:
		if (*x - 2 >= 0 && *y + 1 < 8 && chess[*x - 2][*y + 1] == 0)
		{
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	case 6:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*x -= 1;
			*y -= 2;
			return 1;
		}
		break;
	case 7:
		if (*x - 1 >= 0 && *y + 2 < 8 && chess[*x - 1][*y + 2] == 0)
		{
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	default:
		break;
	}
    return 0;
}
int horsetravel(int x, int y, int tag)
{
	chess[x][y] = tag;
	int x1 = x, y1 = y, flag = 0, c = 0;
	if (tag == 64)//如果走满了棋盘，就打印棋盘
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << chess[i][j];
				if (chess[i][j] < 10)
					cout << "  ";
				else
					cout << " ";
			}		
			cout << endl;
		}
		return 1;
	}
	//判断下一步能不能走
	while (c < 8)
	{
		flag = next(&x1, &y1, c);
		if (flag)
			break;
		c++;
	}
	while (flag)
	{
		if (horsetravel(x1, y1, tag + 1))		
			return 1;	
		//如果该走法不行，再换一种走法
		x1 = x;
		y1 = y;
		c++;
		//必须先把flag设置为0
		for (flag = 0; c < 8; c++)
		{
			flag = next(&x1, &y1, c);
			if (flag)
				break;
		}
	}
	if (flag == 0)//如果该走法后续的走法不行，则退回去
		chess[x][y] = 0;
	return 0;
}