#include<iostream>
using namespace std;
const int N = 1E3 + 5;
int s[N],h[N];

void inti_set(int n){
	for(int i = 1; i <= n; i++) {
		s[i] = i;
		h[i] = 0;
	}
}

// 路径压缩
int find_set(int x){
	if(x != s[x]) s[x] = find_set(s[x]);
	return s[x];
}

void union_set(int x, int y){
	x = find_set(x);
	y = find_set(y);
	
	if (x == y) return;
	
	else if(h[x] == h[y]){
		h[y] = h[y] + 1;
		s[x] = y;
	}
	
	else if (h[x] < h[y]) {
		s[x] = y;
	}
	else s[y] = x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,t,x,y;
	cin >> t;
	while(t--){
		cin >> n >> m;
		inti_set(n);
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			union_set(x,y);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) if(s[i] == i) ans++;
		cout << ans << "\n";
	}
	return 0;
}

