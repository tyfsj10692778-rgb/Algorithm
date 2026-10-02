#include<iostream>
#include<vector>
using namespace std;

int main()
{	
	ios:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	int M; 
	cin >> M;
	int target = 2*M;
	
	vector<pair<int, int>> ans;
	
	for(int k = 2; k*k <= target; k++)
	{
		if (target % k == 0)
		{
			int temp = (target / k) + 1 - k;
			if (temp % 2 == 0)
			{
				int L = temp / 2;
				int R = k + L - 1;
				ans.push_back({L, R});
			}
		}
	}
	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i].first <<  " " << ans[i].second << "\n";
	return 0;
}
