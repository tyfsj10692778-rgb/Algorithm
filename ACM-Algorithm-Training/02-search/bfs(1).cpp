/*
1. how to make 2 dimensions become 1 dimension？
2.pls simulate the process of bfs
i.e.
The most hard part lies in line 37 to 52.
Rewrite it to understand the nature of bfs.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>

const int N = 10;
using namespace std;


int bfs(string start)
{   
	string end = "12345678x";
	if (start == end) return 0;
	
	queue<string>q;
	unordered_map<string,int>d;
	q.push(start);
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	while(!q.empty())
	{
		auto t = q.front();
		if(t == end) return d[t];
		q.pop();
		
		int dist = d[t];
		int k = t.find('x');
		int x = k / 3;
		int y = k % 3;
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{   
				swap(t[k],t[nx * 3 + ny]);
				if(!d.count(t))
				{
					d[t] = dist + 1;
					q.push(t);
				}
				swap(t[k],t[nx * 3 + ny]);
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string start;
	for(int i = 0 ; i < 9; i++)
	{
		char c;
		cin >> c;
		start += c;
	}
	cout << bfs(start);
	return 0;
}
