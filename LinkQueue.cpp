// LinkQueue.cpp : 定义控制台应用程序的入口点。
//front是头指针（没有存数据，在后面删数据），rear是尾指针，存队尾数据（就是新添加的数据），指向地址为NULL

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

template<typename DataType>
struct Node
{
	DataType data;
	Node<DataType>*next;
};
template<typename DataType>
class LinkQueue
{
public:	
	LinkQueue();
	~LinkQueue();
	void EnQueue(DataType e);
	DataType DeQueue();
	void PrintQueue();
private:

	
	Node<DataType> *rear;//指向最后一个节点，存数据
	Node<DataType> *front;//类似于头节点，不存数据
	
	
};

int main()
{
	LinkQueue<int> LQueue;
	LQueue.EnQueue(3);
	LQueue.EnQueue(4);
	LQueue.EnQueue(5);
	LQueue.EnQueue(6);
	LQueue.EnQueue(7);
	LQueue.PrintQueue();
	cout<<LQueue.DeQueue()<<endl;
	LQueue.PrintQueue();

	cin.get();
	cin.get();
	return 0;
}


template<typename DataType>
LinkQueue<DataType>::LinkQueue()
{
	Node<DataType>*p = new Node<DataType>;
	p->next = NULL;
	front = rear=p;
}

template<typename DataType>
LinkQueue<DataType>::~LinkQueue()
{
	Node<DataType>*p = new Node<DataType>;
	while (front->next != rear)
	{
		p = front->next;		
		front->next = p->next;		
		delete p;
	}
	delete front;
	delete rear;
}

template<typename DataType>
void LinkQueue<DataType>::EnQueue(DataType e)
{
	Node<DataType>*p = new Node<DataType>;
	p->data = e;
	p->next = NULL;
	rear->next = p;
	rear = p;
	cout << "input is ok!" << endl;
	
	
}

template<typename DataType>
DataType LinkQueue<DataType>::DeQueue()
{
	
	
	if(front != NULL)
	{
		Node<DataType>*p = new Node<DataType>;
		DataType x;
		p = front->next;
		x = p->data;
		front->next = p->next;
		delete p;
		return x;
	}
	else
	{
		throw"the queue is empty!";
	}
}


template<typename DataType>
void LinkQueue<DataType>::PrintQueue()
{
	Node<DataType>*p = front->next;
	while (p->next != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data <<endl;
}
