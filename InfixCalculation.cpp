// InfixExpression.cpp : 定义控制台应用程序的入口点。
//1.使用栈将中缀表达式转为后缀表达式
//2.对后缀表达式进行计算

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string>//就可以cout了
using namespace std;


//顺序存储栈->finished
const int MAXSIZE = 100;
template<class Datatype>
class SqStack
{
public:
	SqStack();
	~SqStack(){}
	void Push(Datatype e);
	Datatype Pop();
	Datatype GetTop();
	void isEmpty();
	int Length();
	void PrintStack();
private:
	Datatype data[MAXSIZE];
	int top;//栈顶指针
};

bool OpAisSmallerThanOpB(string opA, string opB);

void InfixToPost(SqStack<string> s, SqStack<string> &ans);

int InfixCalculation(SqStack<string> ans);

int main()
{
	SqStack<string> s;
				
	s.Push("2");
	s.Push("/");
	s.Push("10");
	s.Push("+");
	s.Push("3");
	s.Push("*");
	s.Push(")");
	s.Push("1");
	s.Push("-");
	s.Push("3");
	s.Push("(");
	s.Push("+");
	s.Push("9");
	s.PrintStack();
	/*
	s.Push("1");
	s.Push("+");
	s.Push("3");
	*/
	//cout << s.GetTop() << endl;
	SqStack<string> ans;
	InfixToPost(s, ans);
	ans.PrintStack();
	int ans_cal;
	ans_cal = InfixCalculation(ans);
	cout << "the ans is " << ans_cal << endl;
	cin.get();
	cin.get();
	return 0;
}






//类的函数定义
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
	if (top != -1)
	{
		
		Datatype x;
		x = data[top];
		top--;
		return x;
	}
}

template<class Datatype>
Datatype SqStack<Datatype>::GetTop()
{
	if (top != -1)
	{
		return data[top];
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
	return top + 1;
}


//普通函数定义
bool OpAisSmallerThanOpB(string opA, string opB)
{
	//判断是否opA的优先级更低
	if (((opA == "+") && ((opB == "*") || (opB =="/") || (opB == ")"))) || ((opA == "-") && ((opB == "*") || (opB == "/") || (opB == ")"))))
	{
		return  true;
	}
	else
	{
		return false;
	}
}



void InfixToPost(SqStack<string> s, SqStack<string> &ans)
{//函数定义完成
	int n = s.Length();
	SqStack<string> tmp;//记录运算符
	//SqStack<char> ans;//记录后缀表达式

	
	while (n>0)//读取中缀表达式，数字直接存到ans里
	{
		string s_top = s.Pop();//弹出的数
		//cout << "s_top = " << s_top << endl;
		if (s_top != "+"&&s_top != "-"&&s_top != "*"&&s_top != "/"&&s_top != "("&&s_top != ")")
		{//弹出的数字
			//cout << " number " << endl;
			ans.Push(s_top);
		}
		else
		{//弹出的字符
			//cout << " charater " << endl;
			if (tmp.Length() == 0||s_top=="(")
			{//临时符号栈空，直接压入
				tmp.Push(s_top);
				//cout << "tmp:    ";
				//tmp.PrintStack();
				//cout << tmp.Length() << endl;
			}
			else
			{//临时符号栈非空，判断优先级
				//cout << "tmp的长度： " << tmp.Length() << endl;
				//tmp.PrintStack();
				if (s_top == ")")
				{
					//cout << "如果是右括号，临时栈不断弹出，知道遇到左括号，并压入ans栈" << endl;
					//int nums = tmp.Length();
					//for (int i = 0;i<)
					while (tmp.GetTop() != "("&&tmp.Length() != 0)
					{
						string s_tmp;
						s_tmp = tmp.Pop();
						//cout << "tmp的长度： "<<tmp.Length() << endl;
						//cout << "tmp的弹出： " << s_tmp << endl;
						//cout << "tmp的栈顶： " << tmp.GetTop() << endl;
						if (s_tmp != "(")
						{
							ans.Push(s_tmp);
						}
						//cout << "ans的栈顶： " <<ans.GetTop()<< endl;
					}
					//cout<<tmp.GetTop()<<endl;
					//cout << "遇到）" << tmp.Length() << endl;
					if (tmp.GetTop() == "(")
					{
						tmp.Pop();
					}

				}
				else if(OpAisSmallerThanOpB(s_top, tmp.GetTop()))
				{
					//低优先级
					//如果是低优先级，临时栈不断弹出，并压入ans栈，最后临时栈压入该运算符
					while (tmp.Length() != 0)
					{
						string s_tmp;
						s_tmp = tmp.Pop();
						ans.Push(s_tmp);
					}
					tmp.Push(s_top);
						
					
				}
					
				
				else
				{
					//cout << "非低优先级！" << endl;
					//高优先级，直接压入
					tmp.Push(s_top);
					//tmp.PrintStack();
					
				}
			}
		}
		n--;
	}
	while (tmp.Length() != 0)
	{
		string s_tmp;
		s_tmp = tmp.Pop();
		ans.Push(s_tmp);
	}
		
	
	cout << "PostExpresion is ok!"<<endl;
}


int InfixCalculation(SqStack<string> ans)
{//finished
	SqStack<string> tmp;
	SqStack<string> ans_reverse;
	int n = ans.Length();
	cout << "the length of ans = " << ans.Length() << endl;
	for (int i = 0; i < n; i++)
	{
		string tmp_char;
		tmp_char = ans.Pop();
		ans_reverse.Push(tmp_char);
	}
	ans_reverse.PrintStack();
	cout << "ans_reverse's top is " << ans_reverse.GetTop() << endl;

	//start calculate
	while (n>0)
	{
		string ans_top = ans_reverse.Pop();
		if (ans_top != "+"&&ans_top != "-"&&ans_top != "*"&&ans_top != "/"&&ans_top != "("&&ans_top != ")")
		{
			//是数字
			tmp.Push(ans_top);
		}
		else
		{
			int  a = atoi(tmp.Pop().c_str());
			int  b = atoi(tmp.Pop().c_str());
			int tmp_ans;
			if (ans_top=="+")
			{
				tmp_ans = b + a;
				tmp.Push(to_string(tmp_ans));
			}
			else if (ans_top == "-")
			{
				tmp_ans = b - a;
				tmp.Push(to_string(tmp_ans));
			}
			else if (ans_top == "*")
			{
				tmp_ans = b * a;
				tmp.Push(to_string(tmp_ans));
			}
			else 
			{
				tmp_ans = b / a;
				tmp.Push(to_string(tmp_ans));
			}

		}
		n--;
		tmp.PrintStack();
	}



	cout << "it's time to calculate!!" << endl;
	return atoi(tmp.Pop().c_str());
}
