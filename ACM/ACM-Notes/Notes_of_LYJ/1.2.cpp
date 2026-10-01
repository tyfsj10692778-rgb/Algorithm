/*
the use of Hash and queue.
simulation of queue.
*/
#include<bits/stdc++.h>
using namespace std;
int Hash[1005];
queue<int>mem;

int main()
{
	int m,n;
	cin >> m >> n;
	int cnt = 0;
	while(n--)
	{
		int w; cin >> w;
		
		if(!Hash[w])
		{   
			if(mem.size() == m)
			{
				Hash[mem.front()] = 0;
				mem.pop();
			}
			cnt++;
			Hash[w] = 1;
			mem.push(w);
		}
	}
	cout << cnt;
	return 0;
}
