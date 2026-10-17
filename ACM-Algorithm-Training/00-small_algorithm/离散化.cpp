/*
ACwing 802
思维链条很长。先多做几回再说。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 +10;
int a[N],s[N];
vector<int> all;
vector<pair<int,int>> add,query;

int find(int x)
{
	int l = 0, r = all.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (all[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m; cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		int x, c; cin >> x >> c;
		add.push_back({x,c});
		all.push_back(x);
	}
	
	for(int i = 0; i < m; i++)
	{
		int l,r; cin >> l >> r;
		query.push_back({l,r});
		all.push_back(l); all.push_back(r);
	}
	
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	
	for(auto v : add) a[find(v.first)] += v.second;
	
	for(int i = 1; i <= all.size(); i++) s[i] = s[i - 1] + a[i];
	
	for(auto v: query)
	{
		int L = find(v.first), R = find(v.second);
		cout << s[R] - s[L - 1] << "\n";
	}
	
	return 0;
}
