#include <iostream>
#include <vector>
#include <unordered_set> // 引入无序集合（哈希表）

using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	unordered_set<int> visited; // 用来记录哪些数字已经出现过
	bool is_first = true;       // 用来控制空格的输出
	
	for (int i = 0; i < n; i++) 
	{
		int x;
		cin >> x;
		
		// 如果这个数在哈希表里找不到，说明是第一次出现
		if (visited.count(x) == 0)
		{
			if (!is_first)
			{
				cout << " "; // 不是第一个数字，前面补一个空格
			}
			cout << x;
			is_first = false;
			
			visited.insert(x); // 登记到账本里
		}
	}
	cout << "\n";
}

int main() 
{
	// 面对海量数据，这两行提速必须写
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	  
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	
	return 0;
}
