/*
cf gym 纯数据结构模拟题
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+ 10;

int id_[N],r_[N];
long long t_[N];
bool alive[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q; long long w;
	cin >> q >> w;
	
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
	unordered_map<int,int>pos;
	pos.reserve(2 * q);
	
	int head = 0, tail = 0;
	long long s = 0;
	
	while(q--){
		string op; cin >> op;
		if(op == "ADD"){
			int id, r; long long t;
			cin >> id >> t >> r;
			int i = tail++;
			id_[i] = id, t_[i] = t, r_[i] = r;
			alive[i] = true;
			pos[id] = i;
			s += t;
			pq.push({r,id,i});
			
			while(s > w){
				while(!pq.empty() && !alive[get<2>(pq.top())]) pq.pop();
				if(pq.empty()) break;
				int j = get<2>(pq.top()); pq.pop();
				long long nt = (t_[j] + 1) / 2; 
				s -= t_[j] - nt;
				t_[j] = nt;
			}
			
			while(s > w){
				s -= t_[head];
				alive[head] = false;
				head++;
			}
		} else if(op == "ASK"){
			int id; cin >> id;
			auto it = pos.find(id);
			if(it == pos.end() || !alive[it -> second]) cout << -1 << "\n";
			else cout << t_[it -> second] << "\n";
		}else cout << tail - head << " " << s << "\n";
	}
	return 0;
}
