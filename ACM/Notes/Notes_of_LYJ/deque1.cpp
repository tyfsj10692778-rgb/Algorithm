/*
单调队列模板。
只要最值，因此前面的没后来者数值高直接踢死就好。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+ 10;
int a[N];
deque<int>q;
int main()
{    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
		q.push_back(i);
		if(i >= m)
		{
			while(!q.empty() && q.front() <= i - m) q.pop_front();
			cout << a[q.front()] << " ";
		}
	}
	cout << "\n";
	while(!q.empty()) q.pop_front();
	for(int i = 1; i <= n; i++)
	{
		while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.push_back(i);
		if(i >= m)
		{
			while(!q.empty()&& q.front() <= i - m) q.pop_front();
			cout << a[q.front()] << " ";
		}
	}
	return 0;   
}
