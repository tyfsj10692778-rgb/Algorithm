// P1002 Primiere DP


#include<bits/stdc++.h>
using namespace std;

long long dp[25][25];
bool blocked[25][25];

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int main()
{
	int x,y,hx,hy;
	
	cin >> x >> y >> hx >> hy;
	
	blocked[hx][hy] = true;
	
	for(int i = 0; i < 8; i++)
	{
		int nx = hx + dx[i];
		int ny = hy + dy[i];
		if(nx >= 0 && nx <= x && ny >= 0 && ny <= y) blocked[nx][ny] = true;
	}
	
	dp[0][0] = 1;
	
	for(int i = 0; i <= x; i++) // 建模问题： 从 0 到 x 有 x + 1 个格子。
		for(int j = 0; j <= y; j++)
		{   
			if(i == 0 && j == 0) continue;
			else if(blocked[i][j]) continue;
			else 
			{	
				if(i > 0) dp[i][j] += dp[i - 1][j]; 
				if(j > 0) dp[i][j] += dp[i][j - 1];
			}
			/*
				1. 当前的dp只能从(i - 1, j) 和 (i , j - 1) 来。
				   因此定义dp[i][j] 为在(i , j)处合法的方案总数。
				
				2. 注意数组越界问题。[i - 1] 必须在 i > 0 时才能做。
			*/
		}
	cout << dp[x][y];
	return 0;
}
