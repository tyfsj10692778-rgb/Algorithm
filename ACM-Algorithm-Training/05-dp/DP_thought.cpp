/*
Luogu P1387
转移思想：从[i][j] 到 [i - 1][j], [i][j - 1], [i - 1][j - 1] 来撑起这个正方形。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int matrix[N][N],dp[N][N],Max;

int main()
{    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> matrix[i][j];
	Max = -1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{    
			if(matrix[i][j] == 0) dp[i][j] = 0;
			else dp[i][j] = min(min(dp[i - 1][j - 1],dp[i - 1][j]),dp[i][j -1]) + 1;
			Max = max(dp[i][j],Max);
		}
	cout << Max;
	return 0;
}
