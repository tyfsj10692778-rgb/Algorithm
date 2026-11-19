/*
HDU 1010 奇偶剪枝问题。
太难了。
*/
#include<bits/stdc++.h>
using namespace std;
char g[8][8],vis[8][8];
int n,m,t,flag;
int a,b,c,d;

int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

#define check(x,y) (x>= 0 && x < n && y >= 0 && y < m)

void dfs(int x, int y, int time){
	if(flag) return;
	
	if(g[x][y] == 'D'){
		if(time == t) flag = 1;
		return;
	}
	int tmp = t - time - abs(c - x) - abs(d - y);
	
	if(tmp < 0) return;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if(check(nx,ny) && g[nx][ny] != 'X' && !vis[nx][ny]){
			vis[nx][ny] = 1;
			dfs(nx,ny,time + 1);
			vis[nx][ny] = 0;
		}
	}
	return;
}
int main(){
	while(cin >> n >> m >> t){
		if(n == 0 && m == 0 && t == 0) break;
		for(int i = 0; i < n; i++)
			for(int j = 0;  j < m; j++){
				cin >> g[i][j];
				if(g[i][j] == 'S') a = i, b = j;
				if(g[i][j] == 'D') c = i, d = j;
			}
		memset(vis,0,sizeof vis);
		int tmp = t - abs(c - a) - abs(d - b);
		if(tmp & 1) {cout << "NO\n"; continue;}
		flag = 0;
		vis[a][b] = 1;
		dfs(a,b,0);
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
