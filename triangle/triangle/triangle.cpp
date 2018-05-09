#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle) {
	vector<int> res;
	for (int i = 0; i < triangle.size(); i++)
	{
		res.push_back(triangle[triangle.size()-1][i]);
	}
	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			res[j] = min(res[j], res[j + 1]) + triangle[i][j];
		}
	}
	return res[0];
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> triangle;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		for (int j = 0; j <= i; j++)
		{
			int tmp;
			cin >> tmp;
			temp.push_back(tmp);
		}
		triangle.push_back(temp);
	}
	int res = minimumTotal(triangle);
	cout << res << endl;
}