#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	vector<int> count(n + 1, 0); // 这里初始化为0是因为这是计数器，类似于sum要初始化为0
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		count[a[i]] ++;
		if (count[a[i]] > 2)
		{
			cout << "-1";
			return 0;
		}
	}
	// 到这里接收了数组a的元素，并且统计了元素出现次数。
	
	int unique_count = 0;
	for(int i = 0; i < n; i ++) if (count[i] == 1) unique_count ++; // 养成好习惯。直接从1~n遍历。
	
	
} 
