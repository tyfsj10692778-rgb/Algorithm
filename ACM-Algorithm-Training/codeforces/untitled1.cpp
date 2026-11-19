#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	while(t--){
		vector<int>a(3);
		
		cin >> a[0] >> a[1] >> a[2];
		
		sort(a.begin(),a.end());
		int cnt = 1;
		for(int i = 0; i < 2; i++)
		if(a[i] != a[i + 1]) cnt++;
		cout << cnt << "\n";
	}
	return 0;
}
