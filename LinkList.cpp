// LinkList.cpp : 定义控制台应用程序的入口点。
//

/*
finish!
LinkList()
LinkList(DataType a[],int n)
~LinkList()
int legth()
DataType Get(int i)
int Locate(DataType x)
void insert(int i,Datatype x)
DataType delete(int i)
void PrintList()
*/

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	int length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType> *first;//only need head pointer

};

//template<class DataType>
int main()
{
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	LinkList<int> linklist(a,8);
	linklist.PrintList();
	cout << "the length of linklist is : " << linklist.length() << endl;
	cout << "the number in 4 location is : " << linklist.Get(4) << endl;
	cout << "5 is at "<< linklist.Locate(5) << endl;
	cout << "at 2 add number 19" << endl;
	linklist.Insert(2, 19);
	linklist.PrintList();
	cout << "delete the third number : " << linklist.Delete(3) << endl;
	linklist.PrintList();
	cin.get();
	cin.get();
	return 0;
}

template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = NULL;//head pointer
	for (int j = 0; j < n; j++)
	{
		Node<DataType> *s=new Node<DataType>;//creat a new node
		s->data = a[j];
		s->next = first->next;//head insertion
		first->next = s;
	}
}

template<class DataType>
LinkList<DataType>::~LinkList()
{	
	while (first != NULL)
	{
		Node<DataType> *q;//put in "while" to avoid invaid create;
		q = first;
		first = q->next;
		delete q;
	}	
}

template<class DataType>
int LinkList<DataType>::length()
{
	Node<DataType> *q;
	q = first->next;
	int ans = 0;
	while (q != NULL)
	{
		ans++;
		q = q->next;
	}
	return ans;
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;//don't need a new node ,only need a pointer
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	//DataType ans;
	int nums=0;
	Node<DataType> *p = first->next;
	if (i<1)
	{
		throw"Wrong location!";
	}
	else
	{
		while (p != NULL)
		{
			nums++;
			if (nums == i)
			{
				return p->data;
			}
			p = p->next;
		}
	}
	throw"Wrong location!";

}

template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int nums=0;
	while (p != NULL)
	{
		nums++;
		if (p->data == x)
		{
			return nums;
		}
		p = p->next;
	}
	throw" no number!";
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	if (i < 1)
	{
		throw"Wrong location!";
	}
	else
	{
		int nums = 0;
		Node<DataType> *p = first->next;
		while (p != NULL)
		{
			nums++;
			if (nums == i - 1)
			{
				Node<DataType> *q = new Node<DataType>;
				q->data = x;
				q->next = p->next;
				p->next = q;
			}
			else
			{
				p = p->next;
			}
		}
	}
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	int nums = 0;
	Node<DataType> *p = first->next;
	if (i < 1)
	{
		throw " wrong location!" ;
	}
	else
	{
		while (p != NULL)
		{
			nums++;
			if (nums == i - 1)
			{
				DataType ans;
				ans = p->next->data;
				p->next = p->next->next;

				return ans;

			}
			p = p->next;
		}
	}
	throw" no number";
}
