#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		bool red = true;
		int cnt = 0;
		for(int i = 0; i < s.size(); i++){
			if((s[i] == 'R' && red == false)){
				cnt++; red = true;
			}
			else if((s[i] == 'B' && red == true)){
				cnt++; red = false;
			}
			else if(red == false) red = true;
			else if(red == true) red = false;
		}
		cout << cnt << "\n";
	}
	return 0;
}
