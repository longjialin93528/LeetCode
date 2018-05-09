#include<iostream>
using namespace std;
int singleNumber(int A[], int n) {
	int res = 0;
	int flag;
	for (int i = 0; i < 32; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if(A[j]&1==1)
			{
				flag++;
			}
			A[j]=A[j] >> 1;
		}
		flag = flag % 3;
		flag = flag << i;
		res = res | flag;
	}
	return res;
}
int main()
{
	int a[4] = { 111,111,111,2 };
	cout << singleNumber(a, 4) << endl;
}