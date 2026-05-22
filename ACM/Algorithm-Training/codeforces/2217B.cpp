#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() 
{
	
	int n, k;
	
	cin >> n >> k;
	
	vector<int> a(n + 2, 0); 
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	
	
	int p;
	
	cin >> p; 
	
	int target = a[p];
	
	vector<int> y(n + 2, 0); 
	
	for (int i = 1; i <= n; i++) y[i] = (a[i] != target ? 1 : 0);
		
	int L = 0 , R = 0;
	
	for (int i = 0; i < p; i++) if (y[i] != y[i+1]) L++;
	
	for (int i = p; i <= n; i++) if (y[i] != y[i+1]) R++;
	cout << max(L, R) << endl;
}

int main() 
{	
	ios_base::sync_with_stdio(false);
	
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--) solve();
	
	return 0;
	
}
