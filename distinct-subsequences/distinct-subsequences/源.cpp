/*
*  �� A C E
*�� 1 0 0 0
*A  1
*B  1
*C  1
*E  1
*/
#include<iostream>
#include<string>
using namespace std;
int numDistinct(string S, string T)
{
	int row = S.length();
	int col = T.length();
	int **dp = (int**)malloc(sizeof(int*)*(row + 1));
	for (int i = 0; i <= row; i++)
	{
		dp[i] = (int *)malloc(sizeof(int)*(col + 1));
	}
	for (int i = 0; i <= row; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 1; j <= col; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (S[i-1] == T[j-1])//!!!!!!!!!!!ע���ھ������i=1,j=1ʱ����Ӧ���ַ����׸���Ӧ�����ַ����±�Ϊ0������Ҫ��һ��������
				//������ȣ���S[0]��S[i]�а���T[0]��T[j]���Ӵ��ĸ���ȡ����S[0]��S[i-1]�а���T[0]��T[j-1]���Ӵ��ĸ���+
				                         //S[0]��S[i-1]�а���T[0]��T[j]���Ӵ��ĸ���(������S[j]��)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}

	}
	return dp[row][col];
}
int main()
{
	string s("b");
	string t("a");
	int res = numDistinct(s, t);
	cout << res << endl;
}