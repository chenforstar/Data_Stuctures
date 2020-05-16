template<class Datatype>
class LinkStack
{
public:
	template<class Datatype>
	struct Node
	{
		Datatype data;
		Node<Datatype> *next;
	};
	LinkStack();
	~LinkStack();
	void Push(Datatype e);
	Datatype Pop();
	int Length();
	void isEmpty();
	void PrintStack();
private:
	Node<Datatype> *top;//既作为头节点，也作为栈顶
};

template<class Datatype>
LinkStack<Datatype>::LinkStack()
{
	top = new Node<Datatype>;
	top->next = NULL;
}

template<class Datatype>
LinkStack<Datatype>::~LinkStack()
{
	while (top != NULL)
	{
		Node<Datatype> *p = top;
		top = top->next;
		delete p;
	}
}

template<class Datatype>
void LinkStack<Datatype>::Push(Datatype e)
{
	Node<Datatype> *p = new Node<Datatype>;
	p->data = e;
	p->next = top->next;
	
	top->next = p;
}

template<class Datatype>
Datatype LinkStack<Datatype>::Pop()
{
	if (top->next == NULL)
	{
		throw"wrong location!";
	}
	else
	{
		Node<Datatype> *p = top->next;
		top->next = p->next;
		return p->data;
	}
}

template<class Datatype>
int LinkStack<Datatype>::Length()
{
	int count = 0;
	Node<Datatype> *p = top->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

template<class Datatype>
void LinkStack<Datatype>::isEmpty()
{
	if (top == NULL)
	{
		cout << "the stack is empty!" << endl;
	}
	else
	{
		cout << "the stack is not empty!" << endl;
	}
}

template<class Datatype>
void LinkStack<Datatype>::PrintStack()
{
	//only need a point
	Node<Datatype> *p=top->next;
	cout << "the list is : ";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
