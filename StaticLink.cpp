// StaticLink.cpp : 定义控制台应用程序的入口点。
//
/*
静态链表
不使用指针，使用数组+游标表示
*/
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;
const int MAXSIZE = 10;
template <typename Datatype>
class StaticLink
{
public:
	struct Node
	{
		Datatype data;
		int next;
	};
	StaticLink();
	StaticLink(Datatype a[],int n);
	~StaticLink(){}
	Datatype Get(int i);
	int Locate(Datatype e);
	void Insert(Datatype e, int i);
	Datatype Delete(int i);
	void PrintList();
private:
	Node SList[MAXSIZE];
	int length;
};
int main()
{
	int a[5] = { 6, 7, 8, 9, 10 };
	StaticLink<int> SLINK(a,5);
	SLINK.PrintList();
	cout << "the third number is : " << SLINK.Get(3)<<endl;
	int e = 9;
	cout << e << " is locate at  " << SLINK.Locate(e) << endl;
	SLINK.Insert(12, 4);
	SLINK.PrintList();
	cout << endl;
	cout<<SLINK.Delete(2)<<endl;
	SLINK.PrintList();
	cin.get();
	cin.get();
	return 0;
}

template <typename Datatype>
StaticLink<Datatype>::StaticLink()
{
	length = 0;
}

template <typename Datatype>
StaticLink<Datatype>::StaticLink(Datatype a[], int n)
{
	length = n;
	SList[0].next = 1;
	SList[MAXSIZE - 1].next = 0;
	for (int i = 1; i <= n; i++)
	{
		SList[i].data = a[i - 1];
		SList[i].next = i + 1;

	}

}

template <typename Datatype>
Datatype StaticLink<Datatype>::Get(int i)
{
	int m = 0;
	int j;//记录是第几个元素
	if (i>length)
	{
		throw"wrong location!";
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			m = SList[m].next;
		}
		return SList[m].data;
	}
	
}

template <typename Datatype>
int StaticLink<Datatype>::Locate(Datatype e)
{
	int m = 0;
	for (int i = 0; i < length; i++)
	{
		m = SList[m].next;
		if (SList[m].data == e)
		{
			return m;
		}
	}
	return -1;
}

template <typename Datatype>
void StaticLink<Datatype>::Insert(Datatype e, int i)
{
	//firstly,put the data in the location of length+1,then find the last element before the location i;
	if (i > length)
	{
		throw" wrong location!";

	}
	else
	{
		SList[length + 1].data = e;
		int m = 0;
		for (int j = 0; j < i-1; j++)
		{
			m = SList[m].next;
		}
		SList[m].next = length + 1;
		SList[length + 1].next = i;
		SList[length].next++;
		length++;
	}
}

template <typename Datatype>
Datatype StaticLink<Datatype>::Delete(int i)
{
	int m = 0;
	if (i > length)
	{
		throw"wrong location!";
	}
	else
	{
		int m = 0;
		for (int j = 0; j < i-1; j++)
		{
			m = SList[m].next;
		}
		cout << m << endl;
		Datatype tmp = SList[SList[m].next].data;
		SList[m].next = SList[SList[m].next].next;

		length--;
		return tmp;
	}
}

template <typename Datatype>
void StaticLink<Datatype>::PrintList()
{
	int m = 0;
	for (int i = 0; i < length; i++)
	{
		m = SList[m].next;
		cout <<"{"<< m<<"}" << " : " << SList[m].data << endl;
	}
	cout << endl;
		
	
}


