const int MAXSIZE = 10;
template<class Datatype>

class BothStack
{
public:
	BothStack();
	~BothStack(){}
	void Push(int i, Datatype e);
	Datatype Pop(int i);
	void Lenth();
	void isEmpty();
	void PrintStack();
private:
	Datatype data[MAXSIZE];
	int top1, top2;
};

template<class Datatype>
BothStack<Datatype>::BothStack()
{
	top1 = -1;
	top2 = MAXSIZE;
}

template<class Datatype>
void BothStack<Datatype>::Push(int i, Datatype e)
{
	if (top2 == top1 - 1)
	{
		throw"stacks are full!";
	}
	else
	{
		if (i == 1)
		{
			top1++;
			data[top1] = e;
		}
		else if (i == 2)
		{
			top2--;
			data[top2] = e;
		}
		else
		{
			cout << "there only have 2 stacks!" << endl;
		}
	}
}

template<class Datatype>
Datatype BothStack<Datatype>::Pop(int i)
{
	
	if (i == 1)
	{
		if (top1 == -1)
		{
			throw"stack1 is empty!";
		}
		return data[top1--];		
		

	}
	else
	{
		if (top2 == MAXSIZE)
		{
			throw"stack2 is empty!";
		}
		return data[top2++];
			
			
		
	}
	//else
	//{
	//	cout << "there only have 2 stacks!" << endl;
	//	return -1;
	//}
}

template<class Datatype>
void BothStack<Datatype>::Lenth()
{
	int a[2];
	a[0] = top1 + 1;
	a[1] = MAXSIZE - top2;
	cout << "the length of stack1 is " << a[0] << endl;
	cout << "the length of stack2 is " << a[1] << endl;
}

template<class Datatype>
void BothStack<Datatype>::isEmpty()
{
	if (top1 == -1)
	{
		cout<<"stack1 is empty!"<<endl;
	}
	else
	{
		cout << "stack1 is not empty!" << endl;
	}
	if (top1 == MAXSIZE)
	{
		cout << "stack2 is empty!" << endl;
	}
	else
	{
		cout << "stack2 is not empty!" << endl;
	}
}

template<class Datatype>
void BothStack<Datatype>::PrintStack()
{
	int a = top1;
	int b = top2;
	cout << "the first stack is : ";
	while(a != -1)
	{
		cout << data[a] << " ";
		a--;
	}
	cout << endl;

	cout << "the second stack is : ";
	while (b != MAXSIZE)
	{
		cout << data[b] << " ";
		b++;
	}
	cout << endl;
}
