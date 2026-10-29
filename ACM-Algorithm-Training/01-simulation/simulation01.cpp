#include<bits/stdc++.h>
using namespace std;
int a[305],f[305];

int n,k;

int mex(int x){
	
	vector<bool>seen(305,false);

	for(int i = 1; i <= x; i++)
	seen[a[i]] = true;
	
	int t = 0;
	while(seen[t]) t++;
	
	return t;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	
	while(t--){
		
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 1; i <= n; i++) {f[i] = mex(i);}
		
		int bi = 1, bj = 2, maxm = f[n - k + 1];
		
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++){
				
				swap(a[i],a[j]);
				
				int p = mex(n - k + 1);
				
				if(p > maxm) {bi = i; bj = j; maxm = p;}
				
				swap(a[i],a[j]);
			}
		
		if(maxm == f[n - k +1]) cout << "-1\n";
		else cout << bi << " " << bj << "\n";
	}
	return 0;
}
