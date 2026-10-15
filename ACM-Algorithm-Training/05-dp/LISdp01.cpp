/*
LIS DP 模板 B3637
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5E3 + 10;
int L[N], num[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> num[i];
	
	for(int i = 1; i <= n; i++)
	{
		int maxm = 0;
		for(int j = 1; j < i; j++)
			if(L[j] > maxm && num[j] < num[i]) maxm = L[j];
		L[i] = maxm + 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(L[i] > ans) ans = L[i];
	cout << ans;
	return 0;
}
