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
	
	DoubleLink<int> DLink;

	DLink.PrintList();
	cout << "the length of this list is : " << DLink.Length() << endl;
	
	DLink.Insert(4,1);
	DLink.Insert(2,2);
	DLink.Insert(3,3);
	DLink.PrintList();
	DLink.Delete(2);
	DLink.PrintList();
	DLink.Delete(2);
	DLink.PrintList();
	DLink.Insert(2, 2);
	DLink.Insert(3, 3);

	DLink.PrintList();
	cout << "the elements in 2 is : " << DLink.Get(2) << endl;
	cout << "number 4 is at " << DLink.Locate(4) << endl;
	cout << "OK!" << endl;
	cin.get();
	cin.get();

	return 0;
}

//试图搞一个循环双向链表
template<typename DataType>
DoubleLink<DataType>::DoubleLink()
{
	first = new DoubleNode<DataType>;
	first->next = first;
	first->prior = first;
}

template<typename DataType>
DoubleLink<DataType>::DoubleLink(DataType a[], int n)
{
	first = new DoubleNode<DataType>;
	first->next = NULL;
	
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
	while (first->next != first)
	{
		DoubleNode<DataType> *s = new DoubleNode<DataType>;
		s = first->next;
		first->next = s->next;
		s->next->prior = first;
		delete s;
	}
	
	delete first;

}



template<typename DataType>
int DoubleLink<DataType>::Length()
{
	int count = 0;
	DoubleNode<DataType> *s = first->next;
	while (s != first)
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
	while (s != first)
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
	while (s != first)
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
	if (s == first)
	{
		DoubleNode<DataType>*p = new DoubleNode<DataType>;
		p->data = e;
		p->next = first;
		first->next = p;
	}
	else
	{
		while (s != first)
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
	}
	/*if (i > count)
	{
		throw"wrong location!";
	}*/
}

template<typename DataType>
DataType DoubleLink<DataType>::Delete(int i)
{
	int count = 0;

	DoubleNode<DataType>*s = first->next;

	while (s != first)
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

}



template<typename DataType>
void DoubleLink<DataType>::PrintList()
{
	DoubleNode<DataType> *p = new DoubleNode<DataType>;
	p = first->next;
	cout << "the list is : ";
	while (p != first)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
