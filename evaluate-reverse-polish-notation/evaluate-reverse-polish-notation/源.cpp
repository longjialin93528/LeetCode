#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
/*注意出站的数作为操作数的顺序*/
int func(int op1, int op2, string s)
{
	if (s == "+")
		return op1 + op2;
	if (s == "-")
		return op2 - op1;
	if (s == "*")
		return op1 * op2;
	if (s == "/")
		return op2 / op1;
	return 0;
}
int evalRPN(vector<string> &tockens)
{
	int len = tockens.size();
	stack<int> sak;
	for (int i = 0; i < len; i++)
	{
		if (tockens[i] != "+"&&tockens[i] != "-"&&tockens[i] != "*"&&tockens[i] != "/")
		{
			int temp = stoi(tockens[i]);
			sak.push(temp);
		}
		else if (tockens[i] == "+" || tockens[i] == "-" || tockens[i] != "*" || tockens[i] != "/")
		{
			int op1 = sak.top();
			sak.pop();
			int op2 = sak.top();
			sak.pop();
			int res = func(op1, op2, tockens[i]);
			sak.push(res);
		}
	}
	return sak.top();
}
int main()
{
	string s1("2");
	string s2("1");
	string s3("+");
	string s4("3");
	string s5("*");
	vector<string> tockens;
	tockens.push_back(s1);
	tockens.push_back(s2);
	tockens.push_back(s3);
	tockens.push_back(s4);
	tockens.push_back(s5);
	cout << evalRPN(tockens) << endl;
}