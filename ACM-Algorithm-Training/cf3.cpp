#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(),a.end());
		map<int,int>cnt;
		for(auto x : a) cnt[x]++;
		int length = a.size();
		
		int ans = 0;
		for(int i = 0; i < length; i++)
		ans += min(cnt[i],2);
		cout << ans << "\n";
	}
	return 0;
}
