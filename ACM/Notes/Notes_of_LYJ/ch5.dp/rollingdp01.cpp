#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int w[N][N],c[N][N];
int dp[N];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while((cin >> n >> m) && n != 0 && m != 0)
	{
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
			c[i][j] = j;
		}
		memset(dp,0,sizeof dp);
		for(int i = 1; i <= n; i++)
		for(int j = m; j >= 0; j--)
		for(int k = 1; k <= m; k++)
		{if(j >= c[i][k]) dp[j] = max(dp[j],dp[j - c[i][k]] + w[i][k]);}
		cout << dp[m] << "\n";
	}
	return 0;
}
