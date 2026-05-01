#include<iostream>
#include<vector>

using namespace std;

vector<int>add(vector<int>&A,vector<int>&B)
{
	if(A.size()<B.size())return add(B,A);
	
	vector<int>C;
	int k = 0;
	for(int i = 0;i < A.size();i++)
	{
		k+=A[i];
		if(i < B.size())k+=B[i];
		C.push_back(k % 10);
		k /= 10;
	}
	if(k)C.push_back(k);
	return C;
}

int main()
{
	string a,b;
	vector<int>A,B;
	cin>>a>>b;
	for(int i =a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i =b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	
	auto C =add(A,B);
	for(int i = C.size()-1;i>=0;i--)cout<<C[i];
	cout<<endl;
	
	return 0;
}
