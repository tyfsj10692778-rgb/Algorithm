#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],f[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	
	while(t--)
	{
		int n,k; cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		if(a[1] == 0) f[1] = 1;
		else f[1] = 0;
		
		for(int i = 2; i <= n; i++)
		{
			for(int j = 0; j < n; j++)
				
				for(int k = 1; k <= i; k++)
				{
					if(j == a[k]) continue;
					if(j != a[i]) f[i] = j;
				}
		}
		for(int i = 1; i <= n; i++) cout << f[i] << " ";
		cout << "\n";
	}
	return 0;
}
