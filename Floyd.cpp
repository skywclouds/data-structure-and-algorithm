/*
弗洛伊德算法
Author: Henry Wang
Date: 2021-9-14
*/

#include <iostream>

using namespace std;

int g[4][4];

void Floyd();

int main()
{
	g[0][0] = 0;
	g[0][1] = 2;
	g[0][2] = 6;
	g[0][3] = 4;
	g[1][0] = 100;
	g[1][1] = 0;
	g[1][2] = 3;
	g[1][3] = 100;
	g[2][0] = 7;
	g[2][1] = 100;
	g[2][2] = 0;
	g[2][3] = 1;
	g[3][0] = 5;
	g[3][1] = 100;
	g[3][2] = 12;
	g[3][3] = 0;
	Floyd();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)		
			cout << g[i][j] << " ";		
		cout << endl;
	}
		
			
}

void Floyd()
{
	for (int k = 0; k < 4; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
}
