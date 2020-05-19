// String_KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

class kmp
{
public:
	void get_next(string T);
	int KMP(string S, string T, int pos);
//private:
	int next[20];
};



int main()
{
	kmp string_kmp;
	string S = "aaaaab";
	string T = "ab";
	string_kmp.get_next(T);
	for (int i = 0; i < T.size(); i++)
	{
		cout << string_kmp.next[i] << " ";
	}
	cout << endl;
	cout<<string_kmp.KMP(S, T,0) << endl;
	cin.get();
	cin.get();
	return 0;
}

void kmp::get_next(string T)
{
	int t_len = T.size();
	//cout << t_len << endl;
	next[0] = -1;
	//cout << next[0]
		//<< endl;
	int i = 0;//遍历串T->表后缀
	int j = -1;//用于表示回溯的位置->表前缀
	while (i < t_len)
	{
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;//以T[i-1]作为后缀的字串，和匹配的前缀子串的最长长度
		}
		else
		{
			j = next[j];
		}
	}
}

int kmp::KMP(string S, string T, int pos)
{
	int s_len = S.size();
	int t_len = T.size();
	
	get_next(T);
	int i = pos;//定位主串中当前位置
	int j = -1;//回溯的位置
	while (i < s_len&&j < t_len)
	{
		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == t_len)
	{
		return i - j + 1;
	}
	else
	{
		return -1;
	}
}
