/*
Luogu P1115
卡丹算法/DP思想
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
int a[N],dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int Max = a[1];
	dp[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i],a[i]);    
		Max = max(dp[i],Max);
	}
	cout << Max;
	return 0;
}
