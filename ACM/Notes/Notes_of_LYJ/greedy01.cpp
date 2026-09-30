/*
HDU 1003 最大子段和板子
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n; cin >> n;
		int maxsum = -INF;
		int start = 1, end = 1, p = 1;
		int sum = 0;
		
		for(int j = 1; j <= n; j++)
		{
			int a; cin >> a;
			sum += a;
			
			if(sum > maxsum){maxsum = sum; start = p; end = j;}
			
			if(sum < 0)
			{
				sum = 0;
				p = j + 1;
			}
			
		}
		cout << "Case" << " " << i << ":\n" << maxsum << " " << start << " " << end << "\n";
		if(i != t) cout << "\n";
	}
	return 0;
}
