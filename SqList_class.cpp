// SqList_class.cpp : 定义控制台应用程序的入口点。
//

/*
完成，接下来是链式存储

顺序表的模板类
SeqList() 无参构造方法
SeqList(DataType a[],int n) 有参构造方法
~SeqList() 析构函数
int Length() 线性表长度
DataType Get(int i)按位查找
int locate(Datatype x)按值查找
void Insert(int i,DataType x)插入
DataType Delete(int i)删除
void PrintList()遍历
*/
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;
const int MaxSize = 10;
template<typename DataType>

//创建类
class SeqList
{
public:
	SeqList();
	SeqList(DataType a[], int n);
	~SeqList(){}; //析构函数
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();

private:
	DataType m_data[MaxSize];//数组实现线性表
	int m_length;

};
int main()
{
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	SeqList<int> seqlist(a, 8);
	seqlist.PrintList();
	cout << "the length of seqlist : "<<seqlist.Length() << endl;
	cout << "the second number in seqlist is : " << seqlist.Get(2) << endl;
	//cout << "the tenth number in seqlist is : " << seqlist.Get(10) << endl;
	cout<<"8 is at "<<seqlist.Locate(8)<<endl;
	seqlist.Insert(4, 10);
	seqlist.PrintList();
	cout << "delete the second number : " << seqlist.Delete(2) << endl;
	seqlist.PrintList();
	cin.get();
	cin.get();
	return 0;
}

template<typename DataType>
SeqList<DataType>::SeqList()
{
	m_length = 0;
}

template<typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MaxSize)
	{
		throw"Wrong parameter!" ;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			m_data[i] = a[i];
		}
	}
	m_length = n;
}

template<typename DataType>
int SeqList<DataType>::Length()
{
	return m_length;
}

template<typename DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
}

template<typename DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i<1 || i>m_length)
	{
		throw "Wrong location!" ;//
	}
	else
	{
		return m_data[i - 1];
		
	}
}

template<typename DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i = 0; i < m_length; i++)
	{
		if (x == m_data[i])
		{
			return i + 1;
		}
	}
	throw"Wrong data!";
}

template<typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (i<1 || i>m_length)
	{
		throw" Wrong location!";
	}
	else
	{
		for (int j = m_length; j > i-1;j--)
		{
			m_data[j] = m_data[j - 1];
		}
		m_data[i-1] = x;
		m_length++;
	}
}

template<typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (i<1 || i>m_length)
	{
		throw"Wrong location!";
	}
	else
	{
		DataType x;
		x = m_data[i - 1];
		for (int j = i - 1; j < m_length; j++)
		{
			m_data[j] = m_data[j + 1];
		}
		m_length--;
		return x;
	}
}
