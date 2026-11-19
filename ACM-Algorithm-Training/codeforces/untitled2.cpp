/*
cf gyn 106589 A
双端队列。忘了。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

struct node{
	int id;
	int token;
	int r;
	bool zip = false;
}n[N];

bool cmp(node & a, node & b){
	if(a.r != b.r) return a.r < b.r;
	else return a.id < b.id;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long q,w; cin >> q >> w;
	
	int idx = 0;
	long long sum = 0;
	
	deque<node> text(q);
	
	while(q--){
		string s; cin >> s;
		
		if(s == "ADD"){
			cin >> n[idx].id >> n[idx].token >> n[idx].r;
			
			sum += n[idx].token;
			
			sort(n, n + idx,cmp);
			
			if(sum > w){
				for(int i = 0; i < idx; i++){
					if(n[i].zip == false){
						n[i].token /= 2;
						n[i].zip = true;
						if(sum < w)break;
					}
				}
				//if(sum > w) 就要双端队列弹出了。
			}
			idx++;
		}
		else if(s == "ASK"){
			int uid; cin >> uid;
			// 双端队列似乎有判断元素是否在集合里的代码。
			// 不过很明显，我忘了。hhh
		}
		else {
			cout << text.size() << " " << sum << "\n";
		}
	
	}
	return 0;
}
