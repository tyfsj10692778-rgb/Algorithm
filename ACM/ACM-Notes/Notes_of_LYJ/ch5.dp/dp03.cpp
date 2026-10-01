/*
HDU 1003
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n; cin >> n;
		for(int j = 1; j <= n; j++) cin >> dp[j];
		
		int start = 1, end = 1, p = 1;
		int maxsum = dp[1];
		for(int j = 2; j <= n; j++)
		{	
			/*
			最有意思的部分: dp的含义从一个数变为了以i结尾的最大子段和
			要么和前一项dp合并，要么自己单飞 -> 状态转移
			如果单飞就等价于前面的子段和dp是负数。
			*/
			if(dp[j - 1] + dp[j] >= dp[j]) dp[j] = dp[j - 1] + dp[j];
			else p = j;
			if(dp[j] > maxsum)
			{maxsum = dp[j]; start = p; end = j;}
		}
		cout << "Case" << " " << i << ":\n" << maxsum << " " << start << " " << end << "\n";
		if(i != t) cout << "\n";
	}
	return 0;
}
