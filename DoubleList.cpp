// DoubleLink.cpp : 定义控制台应用程序的入口点。
//

//双向链表


#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;
template<typename DataType>
struct DoubleNode
{
	DataType data;
	DoubleNode<DataType> *prior;
	DoubleNode<DataType> *next;
	
};
template<typename DataType>
class DoubleLink
{
public:
	DoubleLink();
	DoubleLink(DataType a[], int n);
	~DoubleLink();
	int Length();
	DataType Get(int i);
	int Locate(DataType e);
	void Insert(DataType e, int i);
	DataType Delete(int i);
	
	void PrintList();
private:
	DoubleNode<DataType> *first;
};
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int n = 5;
	DoubleLink<int> DLink(a, n);
	DLink.PrintList();
	cout<<"the length of this list is : "<<DLink.Length()<<endl;
	//cout << "the elements in 8 is : " << DLink.Get(8) << endl;
	cout << "the elements in 2 is : " << DLink.Get(2) << endl;
	cout << "number 1 is at " << DLink.Locate(1) << endl;
	cout << "add number 8 in location 4 " << endl;
	DLink.Insert(8, 4);
	DLink.PrintList();
	DLink.Delete(6);
	DLink.PrintList();
	DLink.Delete(4);
	DLink.PrintList();
	//cout << "add number 8 in location 8 " << endl;
	//DLink.Insert(8, 8);
	cout << "OK!" << endl;
	cin.get();
	cin.get();

	return 0;
}

template<typename DataType>
DoubleLink<DataType>::DoubleLink()
{
	first = new DoubleNode<DataType>;
	first->next = NULL;
	first->prior = NULL;
}

template<typename DataType>
DoubleLink<DataType>::DoubleLink(DataType a[], int n)
{
	first = new DoubleNode<DataType>;
	first->next = NULL;
	first->prior = NULL;

	DoubleNode<DataType> *p = new DoubleNode<DataType>;
	p->data = a[0];
	p->prior = first;
	p->next = first->next;
	first->next = p;
	

	for (int i = 1; i < n; i++)
	{
		DoubleNode<DataType> *s = new DoubleNode<DataType>;
		s->data = a[i];
		s->prior = first;
		s->next = first->next;
		first->next->prior = s;
		first->next = s;
	}

	
}

template<typename DataType>
DoubleLink<DataType>::~DoubleLink()
{
	while (first->next->next != NULL)
	{
		DoubleNode<DataType> *s = new DoubleNode<DataType>;
		s = first->next;
		first->next = s->next;
		s->next->prior = first;
		delete s;
	}
	delete first->next;
	delete first;
	
}



template<typename DataType>
int DoubleLink<DataType>::Length()
{
	int count = 0;
	DoubleNode<DataType> *s = first->next;
	while (s!= NULL)
	{
		count++;
		s = s->next;

	}
	return count;
}

template<typename DataType>
DataType DoubleLink<DataType>::Get(int i)
{
	int count = 0;
	DoubleNode<DataType>*s = first->next;
	while (s != NULL)
	{
		count++;
		if (i == count)
		{
			return s->data;
		}
		s = s->next;
	}
	throw"wrong location!";
}

template<typename DataType>
int DoubleLink<DataType>::Locate(DataType e)
{
	int nums = 0;
	DoubleNode<DataType>*s = first->next;
	while (s != NULL)
	{
		nums++;
		if (s->data == e)
		{
			return nums;
		}
		s = s->next;
	}
	throw"wrong location!";
}

template<typename DataType>
void DoubleLink<DataType>::Insert(DataType e, int i)
{
	int count = 0;
	DoubleNode<DataType>*s = first->next;
	
	while (s != NULL)
	{
		count++;
		if (count == i - 1)
		{
			DoubleNode<DataType>*p = new DoubleNode<DataType>;
			p->data = e;
			p->next = s->next;
			p->prior = s;
			s->next->prior = p;
			s->next = p;
			
		}
		s = s->next;

	}
	if (i > count)
	{
		throw"wrong location!";
	}
}

template<typename DataType>
DataType DoubleLink<DataType>::Delete(int i)
{
	int count = 0;

	DoubleNode<DataType>*s = first->next;

	while (s != NULL)
	{
		count++;
		if (count == i - 1)
		{
			DoubleNode<DataType>*p = new DoubleNode<DataType>;
			p = s->next;
			if (p->next == NULL)
			{
				s->next = NULL;
				return p->data;
				delete p;
			}
			else
			{
				s->next->next->prior = s;
				s->next = s->next->next;
				return p->data;
				delete p;
			}
			
		}
		s = s->next;
		
	}
	if (i > count)
	{
		throw"wrong location!";
	}
}



template<typename DataType>
void DoubleLink<DataType>::PrintList()
{
	DoubleNode<DataType> *p = new DoubleNode<DataType>;
	p = first->next;
	cout << "the list is : ";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
