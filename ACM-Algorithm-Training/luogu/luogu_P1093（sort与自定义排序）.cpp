#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
	int id;
	int sum;
	int yw;
};

bool cmp(const Student& a, const Student& b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	if (a.yw != b.yw) return a.yw > b.yw;
	return a.id < b.id;
}

int main()
{
	int n; cin >> n;
	vector<Student>Students(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int ch, ma, en; cin >> ch >> ma >> en;
		Students[i].id =i;
		Students[i].sum = ch + ma + en;
		Students[i].yw = ch;
	}
	sort(Students.begin() + 1, Students.begin() + n + 1, cmp);
	for(int i = 1; i <= 5; i ++) cout << Students[i].id << ' ' << Students[i].sum << "\n";
	return 0;
}
