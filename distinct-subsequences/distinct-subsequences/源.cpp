/*
*  空 A C E
*空 1 0 0 0
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
			if (S[i-1] == T[j-1])//!!!!!!!!!!!注意在矩阵里的i=1,j=1时，对应的字符串首个，应该是字符串下标为0，所以要减一！！！！
				//假设相等，则S[0]到S[i]中包含T[0]到T[j]中子串的个数取决于S[0]到S[i-1]中包含T[0]到T[j-1]中子串的个数+
				                         //S[0]到S[i-1]中包含T[0]到T[j]中子串的个数(即不用S[j]项)
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