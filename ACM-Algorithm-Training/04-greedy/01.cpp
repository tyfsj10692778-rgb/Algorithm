/*
ACwing 905 
选取最少的点能够覆盖全体区间。 策略：先让一处端点有序，再尽可能让另一侧区间套娃。
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
		int b,c; cin >> b >> c;
		a.push_back({c,b});
	}
	sort(a.begin(),a.end());
	
	int cnt = 1, position = a[0].first;
	
	for(int i = 1; i < a.size(); i++)
	{
		if(position < a[i].second) {cnt++; position = a[i].first;} 
		else continue;
	}
	cout << cnt;
	return 0;
}
