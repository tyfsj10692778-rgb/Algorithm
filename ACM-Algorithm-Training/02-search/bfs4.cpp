/*
POJ 3278 一维BFS 
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int d[N];

int bfs(int n,int k){
	memset(d,-1,sizeof d);
	queue<int>q;
	q.push(n);
	d[n] = 0;
	while(!q.empty()){
		
		auto t = q.front();
		q.pop();
		if(t == k) return d[t];
		
		int nxt[3] = {t + 1, t - 1, 2 * t};
		
		for(int i = 0; i < 3; i++){
			int x = nxt[i];
			if(x < 0 || x > 1e5 || d[x] != -1) continue;
			d[x] = d[t] + 1;
			q.push(x);
		}
	}
	return -1;
}
int main(){
	int n,k; cin >> n >> k;
	cout << bfs(n,k);
	return 0;
}
