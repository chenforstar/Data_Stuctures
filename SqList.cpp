// SqList.cpp : 定义控制台应用程序的入口点。
//

/*
完成，使用的是结构体；
下一个使用类吧

自定义线性表
1.InitList(&L) 初始化
2.ListEmpty(L) 判断是否是空线性表
3.ShowElem(L)输出线性表
4.ClearList(&L) 清空线性表
5.GetElem(L,i,&e)第i个元素返回给e
6.LocateElem(L,e)判断L中是否与e相等的元素
7.ListInsert(&L,i,e)位置i插入元素
8.ListDelete(&L,i,&e)返回被删除元素给e
9.ListLength(L)线性表的元素个数
*/

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#define MAXSIZE 10//不要加分号
//template <typename T>//只能函数和类？
using namespace std;

//create linear list
struct SqList
{
	int data[MAXSIZE];
	int length;
};

int ListEmpty(SqList &L);
void ClearList(SqList &L);
void ShowElem(SqList L);
int GetElem(SqList L, int i, int &e);
int LocateElem(SqList L, int e);
void ListInsert(SqList &L, int i, int e);
int ListDelete(SqList &L, int i, int &e);
int ListLength(SqList L);

int main()
{
	SqList sqlist;//就是创建了一个空的线性表
	sqlist.length = 8;
	for (int i = 1; i <= 8; i++)
	{
		cout << "请输入第" << i << "个值:";
		cin >> sqlist.data[i];
	}

	cout <<"Is list is empty?  "<< ListEmpty(sqlist)<<endl;	
	ShowElem(sqlist);
	int e;
	int n = 3;
	GetElem(sqlist,n,e);
	cout << "第" << n << "个元素 ： " << e << endl;
	cout << "列表中是否有" << n <<" : "<< LocateElem(sqlist, n) << endl;
	int num = 10;
	cout << "在" << n << "添加" << num << endl;
	ListInsert(sqlist, n, num);
	cout << "线性表的长度为 ：" << ListLength(sqlist) << endl;
	ShowElem(sqlist);
	ListDelete(sqlist, n, num);
	cout << "在" << n << "删除" << num << endl;
	ShowElem(sqlist);
	ClearList(sqlist);
	cout << "Is list is empty?  " << ListEmpty(sqlist) << endl;
	ShowElem(sqlist);

	cin.get();
	cin.get();
	return 0;
}

int ListEmpty(SqList &L)
{
	if (L.length == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void ClearList(SqList &L)
{
	L.length = 0;
}

void ShowElem(SqList L)
{
	int i;
	cout << "elements in the list : ";
	for (i = 1; i <= L.length; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;
}

int GetElem(SqList L, int i, int &e)
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return 0;
	}
	else
	{
		e = L.data[i];
		return 1;
	}
}

int LocateElem(SqList L, int e)
{
	for (int i = 1; i <= L.length; i++)
	{
		if (L.data[i] == e)
		{
			return 1;
		}
	}
	return 0;
}

void ListInsert(SqList &L, int i, int e)
{
	if (i<1 || i>L.length||L.length==MAXSIZE)
	{
		cout << "无法添加元素" << endl;
	}
	else
	{
		for (int j = L.length; j >= i; j--)
		{
			L.data[j + 1] = L.data[j];
		}
		L.data[i] = e;
		L.length++;
	}
	
}

int ListDelete(SqList &L, int i, int &e)
{
	if (i<1 || i>L.length)
	{
		cout << "列表中无该元素" << endl;
		return 0;
	}
	else
	{
		e = L.data[i];
		for (int j = i + 1; j <= L.length; j++)
		{
			L.data[j - 1] = L.data[j];
		}
		L.length--;
		return 1;
	}
}

int ListLength(SqList L)
{
	return L.length;
}
