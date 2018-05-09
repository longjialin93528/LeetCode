#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int len = gas.size();
	int res=-1;
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		res = 0;
		for (int j = i; j < i + len; j++)
		{
			if ((res = res + gas[j%len] - cost[j%len])<0)
			{
				flag = false;
				break;
			}
		}
		if (res >= 0)
		{
			flag = true;
			return i;
			break;
		}
	}
	if (flag == false)
	{
		return -1;
	}
	return res;
}
int main()
{
	vector<int> gas;
	gas.push_back(5);
	gas.push_back(8);
	vector<int> cost;
	cost.push_back(6);
	cost.push_back(4);
	cout << canCompleteCircuit(gas, cost) << endl;
}