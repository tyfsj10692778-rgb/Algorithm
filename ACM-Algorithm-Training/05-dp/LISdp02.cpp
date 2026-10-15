/*
Luogu P1091 LIS模型变式
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 300;
int h[N],L[N],R[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> h[i];
	
	L[1] = 1; R[n] = 1;
	
	
	for(int i = 1; i <= n; i++)
	{	
		int maxm = 0;
		for(int j = 1; j < i; j++)
			if (L[j] > maxm && h[j] < h[i])
				maxm = L[j];
		
		L[i] = maxm + 1;
	}
	
	for(int i = n; i > 0; i--)
	{
		int maxm = 0;
		for(int j = n; j > i; j--)
			if (R[j] > maxm && h[j] < h[i]) maxm = R[j];
		R[i] = maxm + 1;
	}
	int ans = -1;
	for(int i = 1; i <= n; i++)
		if(L[i] + R[i] - 1 > ans) ans = L[i] + R[i] - 1;
	cout << n - ans;
	return 0;
}
