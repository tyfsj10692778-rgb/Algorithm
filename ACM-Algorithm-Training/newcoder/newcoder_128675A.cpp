/*
知识点： 字符串 模拟
注意点： string 库运用 
*/
#include<iostream>
#include<string>
using namespace std;
void solve()
{
	string s;
	cin >> s;
	auto pos = s.find("//");
	if(pos == string::npos) cout << s << endl;
	else if (pos == 0) cout << "null\n";
	else cout << s.substr(0,pos) << endl;
} 
int main()
{
	solve();
	return 0;
}
