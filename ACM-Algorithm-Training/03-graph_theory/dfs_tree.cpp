#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n;
int ans = INT_MAX;

vector<int> g[N];

int dfs(int u, int parent){
	int size = 1, max_size = 0;
	
	for(auto v : g[u]){
		if(v == parent) continue;
		int child_size = dfs(v,u);
		size += child_size;
		max_size = max(max_size,child_size);
	}
	
	max_size = max(max_size,n - size);
	ans = min(max_size,ans);
	
	return size;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	cout << ans;
	return 0;
}
