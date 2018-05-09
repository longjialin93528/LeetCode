#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
/*给定一个字符串，将其分割的每一部分，都是字典里的有效部分*/
bool wordBreak(string s, unordered_set<string> &dict) {
	/*这种方式是前面确定，不断地从后面的可能里确定后面大的*/
	int len = s.length();
	vector<bool> res(len + 1, false);
	res[0] = true;
	for (int i = 0; i <len; i++)
	{
		for (int j = i; res[i]&&j < len; j++)
		{
			if (dict.find(s.substr(i, j-i+1)) != dict.end())
			{
				res[j+1] = true;
			}
		}
	}
	return res[len];
	

}
int main()
{
	unordered_set<string> dict;
	string s("leetcode");
	string s1("leet");
	string s2("code");
	//string s3("l");
	//string s4("code");
	//string s5("leet");
	dict.insert(s1);
	dict.insert(s2);
	//dict.insert(s3);
	//dict.insert(s4);
	//dict.insert(s5);
	bool res = wordBreak(s, dict);
	cout << res << endl;
}