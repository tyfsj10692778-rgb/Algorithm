/*
queue的五个语法
push() 插入元素
pop（）弹出队首元素
front（）显示队首元素 而back ()显示队尾元素
empty（）判断队列是否为空 
size ()队列内元素个数

queue的数据结构决定其不能遍历。 
*/
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n; cin >> n;
	queue <int> q;
	while (n --)
	{
		int a; cin >> a;
		if(a == 1)
		{
			int p; cin >> p;
			q.push(p);
		}
		else if (a == 2)
		{
			if (q.empty()) cout << "ERR_CANNOT_POP" << "\n" ;
			else q.pop();
		}
		else if (a == 3)
		{
			if (q.empty()) cout << "ERR_CANNOT_QUERY" << "\n";
			else cout << q.front() << "\n";
		}
		else if (a == 4) cout << q.size() << "\n";
	}
	return 0;
}
