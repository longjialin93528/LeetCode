#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int candy(vector<int> &ratings) 
{
	vector<int> res;
	vector<int> num;
	int result(0);
	for (int i = 0; i < ratings.size()-1; i++)
	{
		int temp = 0;
		for (int j = i; j < ratings.size() - 1; j++)
		{
			if(ratings[j] > ratings[j + 1])
			{
				temp++;
			}
			else
			{
				break;
			}
		}
		res.push_back(temp);
	}
	res.push_back(0);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	num.push_back(res[0] + 1);
	for (int i = 1; i < ratings.size(); i++)
	{
		int left=1, right;
		if (ratings[i] > ratings[i - 1])
			left = num[i - 1] + 1;
		right = res[i] +1;
		num.push_back(max(left, right));
	}
	for (int i = 0; i < num.size(); i++)
	{
		result += num[i];
	}
	return result;
}
int main()
{
	vector<int> rating;
	rating.push_back(2);
	rating.push_back(2);
	/*
	rating.push_back(4);
	rating.push_back(5);
	rating.push_back(3);
	rating.push_back(9);
	*/
	int res = candy(rating);
	cout << res << endl;
}