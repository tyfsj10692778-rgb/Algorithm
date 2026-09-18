#include <iostream>
#include <vector>
#include <queue> // 引入 C++ 标准队列容器

using namespace std;

int main() 
{
	// 提速快读
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m, n;
	cin >> m >> n;
	
	queue<int> q; // 模拟内存的队列
	vector<bool> in_queue(1005, false); // 账本：记录哪些单词当前在内存中
	
	int ans = 0; // 记录查词典的次数
	
	for (int i = 0; i < n; i++)
	{
		int word;
		cin >> word;
		
		// 如果内存中没有这个单词
		if (!in_queue[word])
		{
			ans++; // 必须查一次词典
			
			// 如果内存满了，需要淘汰最早进入的单词
			if (q.size() == m) 
			{
				int old_word = q.front(); // 找到队头那个最老的单词
				in_queue[old_word] = false; // 账本清空它
				q.pop(); // 把它赶出队列
			}
			
			// 将新单词放入内存
			q.push(word);
			in_queue[word] = true; // 账本登记它
		}
	}
	// 如果这个单词已经在就根本不用鸟hhh
	cout << ans << "\n";
	
	return 0;
}
