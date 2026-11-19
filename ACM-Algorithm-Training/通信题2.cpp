#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	if(s == "first"){
		int x; cin >> x;
		string a;
		for(int i = 7; i >= 0; i--) a.push_back (((x >> i) & 1) + '0');
		cout << a << endl;
	}
	else{
		string a; cin >> a;
		int res = 0;
		for(int i = 7; i >= 0; i--) res += ((a[i] - '0')) << (7 - i);
		cout << res << endl;
	}
}
