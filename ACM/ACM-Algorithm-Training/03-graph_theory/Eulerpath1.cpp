#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int num[N];
int st_edge[10 * N], top_s;
char st_ans[10* N];
int top_a;
int m;
void no_dfs(int v)
{
	int edge;
	while(num[v] < 10)
	{
		edge = 10 * v + num[v];
		num[v]++;
		st_edge[top_s++] = edge;
		v = edge % m;
	}
}
int main()
{
	int n,edge;
	top_s = top_a = edge = 0;
	while(cin >> n && n != 0)
	{
		top_s = top_a = edge = 0;
		m = 1;
		for(int i = 0; i < n - 1; i ++) m *= 10;
		for(int i = 0; i < m; i++) num[i] = 0;
		no_dfs(0);
		while(top_s)
		{
			edge = st_edge[top_s--];
			st_ans[top_a++] = edge % 10 + '0';
			no_dfs(edge/10);
		}
		for(int i = 1 ; i < n; i++) cout << "0";
		while(top_a) cout << st_ans[top_a--];
		cout << "\n";
	}
	return 0;
}
