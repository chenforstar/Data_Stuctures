//顺序存储栈->finished
const int MAXSIZE=10;
template<class Datatype>
class SqStack
{
public:
	SqStack();
	~SqStack(){}
	void Push(Datatype e);
	Datatype Pop();
	void isEmpty();
	int Length();
	void PrintStack();
private:
	Datatype data[MAXSIZE];
	int top;//栈顶指针
};

template<class Datatype>
SqStack<Datatype>::SqStack()
{
	top = -1;
}

template<class Datatype>
void SqStack<Datatype>::Push(Datatype e)
{
	if (top == MAXSIZE - 1)
	{
		throw"wrong location!";
	}
	else
	{
		top++;
		data[top] = e;
	}
}

template<class Datatype>
void SqStack<Datatype>::PrintStack()
{
	for (int i = 0; i <= top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template<class Datatype>
Datatype SqStack<Datatype>::Pop()
{
	if (top == -1)
	{
		throw" empty";
	}
	else
	{
		Datatype x;
		x = data[top];
		top--;
		return x;
	}
}

template<class Datatype>
void SqStack<Datatype>::isEmpty()
{
	if (top == -1)
	{
		cout << "the stack is empty!" << endl;
	}
	else
	{
		cout << "the stack is not empty!" << endl;
	}
}

template<class Datatype>
int SqStack<Datatype>::Length()
{
	return top+1;
}
