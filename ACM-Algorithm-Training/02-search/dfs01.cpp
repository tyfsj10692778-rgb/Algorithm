#include<bits/stdc++.h>
using namespace std;
char g[10][10];
bool col[10];
int n,k;
int cnt;
void dfs (int r , int num)
{	
	
	if (num == k) 	{cnt++;return;}
	if (r > n) return;
	
	dfs(r + 1, num);
	for(int i = 1; i <= n; i++)
	{
		if(g[r][i] == '#' && !col[i])
		{
			col[i] = true; 
			dfs(r + 1, num + 1);	
			col[i] = false; 
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while((cin >> n >> k) && n != -1 && k != -1)
	{
		cnt = 0;
		memset(col,0,sizeof col);
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		cin >> g[i][j];
		dfs(1,0);
		cout << cnt << "\n";
	}
	return 0;
}
