#include <iostream>
#include <map>

using namespace std;

int main() 
{
	// 提升自测和提交的速度
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	// 定义嵌套 map：柜子编号 -> (格子编号 -> 物品)
	map<int, map<int, int>> locker;
	
	while (q--) 
	{
		int type;
		cin >> type;
		
		if (type == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			// 存入物品，如果之前有东西会被直接覆盖，k=0 时也会被写成 0
			locker[i][j] = k;
		} 
		else if (type == 2) {
			int i, j;
			cin >> i >> j;
			// 直接读取并输出对应的物品
			cout << locker[i][j] << "\n";
		}
	}
	
	return 0;
}
