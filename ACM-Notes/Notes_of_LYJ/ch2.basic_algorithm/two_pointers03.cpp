#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
	{
		int n,s; cin >> n >> s;
		
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		int l = 1;
		long long sum = 0;
		int ans = n + 1;
		
		for(int r = 1; r <= n; r++)
		{
			sum += a[r];
			while(sum >= s)
			{
				sum -= a[l];
				ans = min(ans, r - l + 1);
				l++;
			}
		}
		if (ans == n + 1) cout << 0 << "\n";
		else cout << ans << "\n";
	}
		return 0;
}
