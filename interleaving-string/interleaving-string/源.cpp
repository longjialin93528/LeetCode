#include<iostream>
#include<string>
using namespace std;
bool isInterleave(string s1, string s2, string s3)
{
	int row = s1.length();
	int col = s2.length();
	if (row + col != s3.length())
	{
		return false;
	}
	/*
		dp[i][j]����s1��ǰi����s2��ǰj���ܷ񹹳�s3��ǰi+j��
		dp[i][j]ȡ����(dp[i-1][j]Ϊ�棬��s1[i-1]==s3[i+j-1])||(dp[i][j-1]Ϊ�棬��s2[j-1]==s3[i+j-1])||
	*/
	bool **dp = (bool **)malloc(sizeof(bool *)*(row + 1));
	for (int i = 0; i <= row; i++)
	{
		dp[i] = (bool *)malloc(sizeof(bool)*(col + 1));
	}
	dp[0][0] = true;
	for (int i = 1; i <= row; i++)
	{
		dp[i][0] = (dp[i - 1][0] && (s1[i - 1] == s3[i - 1]));
	}
	for (int j = 1; j <= col; j++)
	{
		dp[0][j] = (dp[0][j - 1] && (s2[j - 1] == s3[j - 1]));
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			dp[i][j] = ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])));
		}
	}
	return dp[row][col];
}
int main()
{
	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbcbcac");
	bool res = isInterleave(s1, s2, s3);
	cout << res << endl;
}