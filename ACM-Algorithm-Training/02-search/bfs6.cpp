#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
bool prime[N];
int d[N];

void init(){
	fill(prime + 2, prime + N, true);
	
	for(int i = 2; i * i < N; i++){
		if(prime[i]){
			for(int j = i * i; j < N; j += i) prime[j] = false;
		}
	}
}

int bfs(int a, int b){
	memset(d,-1,sizeof d);
	queue<int>q;
	q.push(a);
	d[a] = 0;
	
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(t == b) return d[t];
		
		for(int p = 1; p <= 1000; p *= 10){
			int old = t / p % 10;
			
			for(int dig = 0; dig < 10; dig++){
				if(dig == old) continue;
				if(p == 1000 && dig == 0) continue;
				
				int x = t + (dig - old) * p;
				
				if(d[x] != -1 || !prime[x]) continue;
				
				d[x] = d[t] + 1;
				q.push(x);
			} 
		}
	}
	return -1;
}
int main(){
	init();
	int t; cin >> t;
	while(t--){
		int a,b; cin >> a >> b;
		int ans = bfs(a,b);
		if(ans == -1) cout << "Impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}
