#include<iostream>
using namespace std;
int singleNumber(int A[], int n)
{
	if (A == nullptr || n <= 0)
	{
		return 0;
	}
	int temp = A[0];
	for (int i = 1; i < n; i++)
	{
		temp ^= A[i];
	}
	return temp;
}
int main()
{
	int a[5] = { 1,1,2,2,5 };
	cout << singleNumber(a, 5) << endl;
}