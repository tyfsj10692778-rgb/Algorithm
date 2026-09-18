#include<iostream>
#include<map>
using namespace std;

int main()
{
	long long n, m, x; cin >> n >> m >> x;
	
	map<long long, int> count;
	
	for(int i = 0; i < n; i ++)
	{
		int a; cin >> a;
		count[a] ++;
	}
	
	int visited = 0; long long low = 0;
	for(auto const& [id,c] : count)
	{
		visited ++;
		if (c <= x) low ++;
	}
	low += m - visited;
	cout << low; 
	return 0;
}
