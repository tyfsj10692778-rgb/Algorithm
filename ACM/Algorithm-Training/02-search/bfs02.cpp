#include<bits/stdc++.h>
using namespace std;

struct Node
{int z, x, y;};

int L, R, C;
char g[35][35][35];
int dist[35][35][35];

int dz[6] = {0,0,0,0,1,-1};
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};

int bfs(Node start)
{
	queue<Node>q;
	q.push(start);
	dist[start.z][start.x][start.y] = 0;
	while(!q.empty())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 6; i++)
		{
			int nz = t.z + dz[i];
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (g[nz][nx][ny] == '#' || dist[nz][nx][ny] != -1) continue;
			if (g[nz][nx][ny] == 'E') return dist[t.z][t.x][t.y] + 1;
			dist[nz][nx][ny] = dist[t.z][t.x][t.y] + 1;
			q.push({nz,nx,ny});
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while((cin >> L >> R >> C) && (L || R || C))
	{
		Node start;
		memset(dist,-1,sizeof dist);
		
		for(int i = 0; i < L; i++)
			for(int j = 0; j < R; j++)
				for(int k = 0; k < C; k++)
				{
					cin >> g[i][j][k];
					if (g[i][j][k] == 'S')
					{ start.z = i, start.x = j, start.y = k;}
				}
		int ans = bfs(start);
		if (ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
	return 0;
}
