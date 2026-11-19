#include<bits/stdc++.h>
using namespace std;
const int N = 1E3 + 10;
int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	if(s == "first"){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		int idx = 0, minm = a[0];
		for(int i = 1; i < n; i++)
			if(a[i] < minm){
				idx = i;
				minm = a[i];
			}
		cout << minm << endl;
	}
			else{
				int n,p; cin >> n >> p;
				cout << "? " << p << endl;
				int ans; cin >> ans;
				cout << "! " << ans << endl;
			}
	return 0;
}
