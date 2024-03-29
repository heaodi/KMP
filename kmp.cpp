#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
int next[1000];

int ViolentMatch(string s, string p)
{
	//暴力匹配，文本串s，模式串p
	int slen = s.length();
	int plen = p.length();
	int i = 0;
	int j = 0;
	while (i<slen && j<plen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}

	}
	//判断是否匹配成功，
	if (j==plen)
	{
		return i-j;
	}
	else {
		return -1;
	}
	
}

int KmpSearch(string s, string p)
{
	int i = 0;
	int j = 0;
	int slen = s.length();
	int plen = p.length();
	while (i<slen && j<plen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if (j == plen)
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}


}




int main()
{
	string s, p;
	/*char p[7] = "hello";
	char s[8];*/
	cin >> s >> p;
	cout << ViolentMatch(s, p) << endl;

	return 0;
}
