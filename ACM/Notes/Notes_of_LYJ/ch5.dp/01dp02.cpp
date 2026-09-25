/*
Luogu 1776 
把m 个相同物品视作不同物品，转化为01背包问题。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int c[N],v[N];
int dp[N][N];

int solve (int i , int j)
{
	if (dp[i][j] != 0) return dp[i][j];
	if (i == 0) return 0;
	int res;
	if (c[i] > j) res = solve(i - 1, j);
	else res = max(solve(i - 1, j) , solve(i - 1, j - c[i]) + v[i]);
	return dp[i][j] = res;
}
/*
注意这个递归是自顶向下，因此要调用最底层得用solve一步步递归
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,C; cin >> n >> C;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		int val, wei, m; cin >> val >> wei >> m;
		for(int j = 0; j < m; j++)
		{v[++cnt] = val; c[cnt] = wei;}
	}   
	cout << solve(cnt,C);
	return 0;
}
