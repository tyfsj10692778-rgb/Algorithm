/*
fucking linked forward star
*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 5, M = 2E6 + 5;
int head[N],cnt;

struct{
	int to,next;
	int w;
}edge[M];

void init()
{
	for(int i = 0; i < N; i++) head[i] = -1;
	for(int i = 0; i < M; i++) edge[i].next = -1;
	cnt = 0;
}

void add_edge(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	init();
	int n,m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		add_edge(u,v);
	}
	for(int i = 0; i <= n; i++) printf("h[%d] = %d ",i, head[i]);
	cout << "\n";
	for(int i = 0; i < m; i++) printf("e[%d].to = %d ",i,edge[i].to);
	cout << "\n";
	for(int i = 0; i < m; i++) printf("e[%d].next = %d ",i,edge[i].next);
	cout << "\n";
	
	for(int i = head[2]; ~i; i = edge[i].next) cout << edge[i].to;
	return 0;
}
