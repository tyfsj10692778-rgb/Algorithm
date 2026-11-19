#include<bits/stdc++.h>
using namespace std;

int lowbit(int x){
	for(int i = 1; i <= x / 2; i *= 2){
		if(x % i == 0 && x % (i * 2) != 0) return i;
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		vector<long long> a(n);
		long long sum = 0;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(),a.end());
		
		while(a.size() > 1){
			int x = a[0] | a[1];
			sum += (lowbit(a[0]) | lowbit(a[1]));
			a.erase(a.begin(),a.begin() + 2);
			a.push_back(x);
			sort(a.begin(),a.end());
		}
		cout << sum << "\n"; 
	}
	return 0;
}
