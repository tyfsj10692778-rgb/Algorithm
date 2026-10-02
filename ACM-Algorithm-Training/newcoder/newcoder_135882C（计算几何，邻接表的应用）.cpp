#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 用一个结构体存点
struct Point 
{
	long long x, y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<Point> p(n);
	
	// 两个账本：
	// count_x[x] 里面存所有横坐标为 x 的点的纵坐标集合
	map<long long, vector<long long>> count_x; // 我没理解为什么这里map里嵌套了long long, vector<long long>
	// count_y[y] 里面存所有纵坐标为 y 的点的横坐标集合
	map<long long, vector<long long>> count_y;
	
	for (int i = 0; i < n; i++) 
	{
		cin >> p[i].x >> p[i].y;
		count_x[p[i].x].push_back(p[i].y);
		count_y[p[i].y].push_back(p[i].x);
	}
	
	// 这一步很关键：把 map 里的 vector 排序，方便后面二分或者做不等于判断
	for (auto &pair : count_x) sort(pair.second.begin(), pair.second.end());
	for (auto &pair : count_y) sort(pair.second.begin(), pair.second.end());
	
	long long ans = 0;
	
	// 两两枚举底边的两个顶点 i 和 j
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			
			// 情况一：纵坐标相同，底边平行于 X 轴
			if (p[i].y == p[j].y) {
				long long sum_x = p[i].x + p[j].x;
				if (sum_x % 2 == 0) 
				{ // 必须能整除 2
					long long target_x = sum_x / 2;
					
					// 去看横坐标为 target_x 的那条垂直线上，有多少个点
					// 只要纵坐标不等于底边的 y 坐标，就是合法的顶角顶点 C
					for (long long y_val : count_x[target_x]) 
					{
						if (y_val != p[i].y)
						{
							ans++;
						}
					}
				}
			}
			
			// 情况二：横坐标相同，底边平行于 Y 轴
			if (p[i].x == p[j].x) 
			{
				long long sum_y = p[i].y + p[j].y;
				if (sum_y % 2 == 0) 
				{ // 必须能整除 2
					long long target_y = sum_y / 2;
					
					// 去看纵坐标为 target_y 的那条水平线上，有多少个点
					// 只要横坐标不等于底边的 x 坐标，就是合法的顶角顶点 C
					for (long long x_val : count_y[target_y]) 
					{
						if (x_val != p[i].x) 
						{
							ans++;
						}
					}
				}
			}
		}
	}
	
	// 【核心避坑：去重】
	// 每一个好三角形会被算几次？
	// 如果它仅仅是“等腰三角形”，它有唯一的底边。我们在枚举这条底边时，它被算了一次。
	// 但是！如果它是“等边三角形”，或者既平行于 X 轴又平行于 Y 轴（即直角腰平行轴，但这题等腰底边平行轴，等边三角形不可能底边同时平行两轴）。
	// 所以每个等腰三角形在我们的算法里，由于底边唯一固定，它【恰好只会被计算一次】！
	// 唯一需要注意的：直角等腰三角形如果底边平行于X轴，它的两腰是不可能平行于Y轴作为底边的。
	// 所以无需除以任何数，直接输出 ans 就是最终答案！
	
	cout << ans << "\n";
	
	return 0;
}
