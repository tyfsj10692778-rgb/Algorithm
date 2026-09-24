#include<iostream>
/*
HDU 2602
the begin of DP. 
draw the dp matrix.
how to trans is the key.
*/
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int w[N],c[N];
int dp[N][N];
int solve(int n, int C)
{
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= C; j++)
		{
			if(c[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - c[i]] + w[i]);
		}
	return dp[n][C];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--)
	{
		int n,C; cin >> n >> C;
		for(int i = 1; i <= n; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) cin >> c[i];
		cout << solve(n,C) << "\n";
		memset(dp,0,sizeof dp);
	}
	return 0;
}
