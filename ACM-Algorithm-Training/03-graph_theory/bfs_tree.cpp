#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int>g[N];

int d[N];

int n,m;

int bfs(){
	memset(d,-1,sizeof d);
	
	queue<int> q;
	q.push(1);
	d[1] = 0;
	
	while(!q.empty()){
		
		auto t = q.front();
		q.pop();
		
		for(auto x : g[t]){
			
			if(d[x] != -1) continue;
			d[x] = d[t] + 1;
			q.push(x);
		}
	}
	return d[n];
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
	} 
	cout << bfs();
	return 0;
}
