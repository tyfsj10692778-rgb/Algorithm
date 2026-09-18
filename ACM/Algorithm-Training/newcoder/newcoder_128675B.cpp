/*
知识点：组合数学 差分 
注意点：using 的妙用 
*/
#include<iostream>
using namespace std;
using LL = long long;
const int p = 998244353;

void solve()
{
	LL n, k, ans = 1;
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) ans = ans * (2 * k + 1) % p; //积的模等于模的积 
	
	cout << ans << '\n';
}
int main()
{
	solve();
	return 0;
}
