#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int prior(char cp)
{
	if(cp=='+' ||cp=='-')
		return 1;
	else if(cp=='*' ||cp=='/')
		return 2;
	else
		return 0;
}

string trans(string in)
{
	stack<char> inf;
	inf.push('@');
	string postfix="";
	string::iterator it;
	for(it=in.begin();it!=in.end();++it)
	{
		if(isalnum(char(*it)))
			postfix+=*it;
		else if(*it=='(')
			inf.push('(');
		else if(*it==')')
		{
			while(inf.top()!='@' && inf.top()!='(')
			{
				postfix+=inf.top();
				inf.pop();
			}
			inf.pop();
		}
		else
		{
			if(prior(*it)>prior(inf.top()))
				inf.push(*it);
			else
			{
				while(inf.top()!='@' && prior(*it)<=prior(inf.top()))
				{
					postfix+=inf.top();
					inf.pop();
				}
				inf.push(*it);
			}
		}
	}
	while(inf.top()!='@')
	{
		postfix+=inf.top();
		inf.pop();
	}
	return postfix;
}


int main()
{
	string infix;
	cin>>infix;
	cout<<trans(infix);
}