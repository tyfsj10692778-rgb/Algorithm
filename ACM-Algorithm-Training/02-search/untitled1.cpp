#include<bits/stdc++.h>
using namespace std;

int dz[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {0,0,0,0,1,-1};
char g[35][35][35];
int d[35][35][35];

int L,C,R;

int bfs(int sz, int sx, int sy, int ez, int ex, int ey){
	memset(d,-1,sizeof d);
	
	queue<tuple<int,int,int>>q;
	q.push({sz,sx,sy});
	d[sz][sx][sy] = 0;
	
	while(!q.empty()){
		auto [z,x,y] = q.front();
		q.pop();
		if(z == ez && x == ex && y == ey) return d[z][x][y];
		for(int i = 0; i < 6; i++){
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nz < 0 || nz >= L || nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if(g[nz][nx][ny] == '#') continue;
			if(d[nz][nx][ny] != -1) continue;
			
			d[nz][nx][ny] = d[z][x][y] + 1;
			q.push({nz,nx,ny});
		}
	}
	return -1;
}
int main(){
	while((cin >> L >> C >> R) && L != 0 && R != 0 && C != 0){
		int sx,sy,sz,ex,ey,ez;
		for(int i = 0; i < L; i++){
			for(int j = 0; j < C; j++){
				for(int k = 0; k < R; k++){
					cin >> g[i][j][k];
					if(g[i][j][k] == 'S'){
						sz = i, sx = j, sy = k;
					}
					if(g[i][j][k] == 'E'){
						ez = i, ex = j, ey = k;
					}
				}
			}
		}
		int ans = bfs(sz,sx,sy,ez,ex,ey);
		if(ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in "  << ans << " minute(s).";
	}
	return 0;
}
