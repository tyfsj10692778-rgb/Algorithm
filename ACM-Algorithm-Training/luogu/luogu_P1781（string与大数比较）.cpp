#include<iostream>
#include<string>
using namespace std;

bool is_greater (const string & a, const string & b)
// 涉及到STL模板库且不改变形参的值，无脑const + & 
// const防止误改， & 极大提高传递效率
{
	if (a.size() != b.size()) return a.size() > b.size();  
	// a.size() 和 a.length() 是一回事。
	//所以用a.size()就好。
	return a > b;
}
int main()
{
	int n; cin >> n;
	int max_id = 1; string max_votes = "0";
	for(int i = 1; i <= n; i ++)
	{
		string current_votes; cin >> current_votes;
		if (is_greater(current_votes, max_votes))
		{
			max_id = i;
			max_votes = current_votes;
		}
	}
	cout << max_id << "\n" << max_votes;
	return 0;
}
