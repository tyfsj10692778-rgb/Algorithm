#include<bits/stdc++.h>
using namespace std;

int a[100];
void findsum(int a[], int n, int s)
{	
	int i = 0;
	int sum = 0;
	
	for(int j = 0; j < n; j++)
	{
		sum += a[j];
		
		while(sum > s)
		{
			sum -= a[i];
			i++;
		}
		if (sum == s) cout << i << " " << j << "\n";
	}
}
int main()
{
	int n, s;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> s;
	findsum(a,n,s);
	return 0; 
}
