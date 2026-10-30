/*
Codeforce div2 B
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char g[2][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		int cnt = 0;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < n; j++){
				cin >> g[i][j];
				if(g[i][j] == 'f') cnt++;
			}
		if(cnt % 2) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
