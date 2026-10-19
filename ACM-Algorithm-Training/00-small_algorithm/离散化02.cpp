/*
Newcode 141877 C
题意简述：给定一群左右端点，端点围成的区间（含端点）+1 （重复计数）
要求输出满足左右端点的和的差绝对值大于p的左右端点组数。
难点在于左右端点值可能很大，需要离散化，前缀和。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int s[N],diff[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,p; cin >> n >> p;
	
	vector<pair<int,int>> a;
	
	for(int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		a.push_back({l,r});
	}
	
	vector<int> v;
	for(auto x : a) {v.push_back(x.first); v.push_back(x.second);}
	sort(v.begin(),v.end());
	
	
	for(auto x : a)
	{
		int l = lower_bound(v.begin(),v.end(),x.first) - v.begin(), r = lower_bound(v.begin(),v.end(),x.second) - v.begin();
		diff[l] += 1; diff[r + 1] -= 1;
	}
	
	s[0] = diff[0];
	
	for(int i = 1; i < v.size(); i++) s[i] = diff[i] + s[i - 1];
	
	int cnt = 0;
	
	for(auto x : a)
	{
		int l = lower_bound(v.begin(),v.end(),x.first) - v.begin(), r = lower_bound(v.begin(),v.end(),x.second) - v.begin(); 
		if(abs(s[l] - s[r]) >= p) cnt++;
	}
	cout << cnt;
	return 0;
}
