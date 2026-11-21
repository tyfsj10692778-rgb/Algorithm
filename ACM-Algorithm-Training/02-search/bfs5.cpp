#include<bits/stdc++.h>
using namespace std;

const int N = 210;

string bfs(int n){	
	
	bool st[205] = {};
	queue<pair<string,int>>q;
	q.push({"1",1 % n});
	st[1 % n] = true;
	if(1 % n == 0) return "1";
	
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		string s = t.first;
		int r = t.second;
		
		for(int i = 0; i < 2; i++){
			
			int nr = (r * 10 + i) % n;
			if(st[nr]) continue;
			
			string ns = s + char('0' + i);
			if(nr == 0) return ns;
			st[nr] = true;
			q.push({ns,nr});
		}
	}
	return "";
}

int main(){
	int a;
	while((cin >> a) && a != 0){
		cout << bfs(a) << "\n";
	}
	return 0;
}
