/*
ACwing 803 思路:

1. pair 存左右端点
2. sort 排序
3. 算法逻辑：比较新区间的左端点与旧区间右端点。

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	int n; cin >> n;
	vector<pair<int,int>> a;
	
	for(int i = 0; i < n; i++)
	{
		int l,r; cin >> l >> r;
		a.push_back({l,r});
	}
	
	sort(a.begin(),a.end());
	
	int st = a[0].first, ed = a[0].second;
	
	int cnt = 0;
	
	for(auto x : a)
	{
		int l = x.first, r = x.second;
		if(ed < l) {cnt++; st = l; ed = r;}
		else ed = max(r,ed);
	}
	cnt++;
	cout << cnt;
	return 0;
}
