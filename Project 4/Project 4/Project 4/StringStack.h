#include <cmath>
#include <iostream>
using namespace std;

struct StackNode
{
	string Text;
	StackNode *Next;
};

class StringStack
{
	public:
		//Constructors
		StringStack();
		StringStack(const StringStack & stack);
		~StringStack();

		//Methods
		bool IsFull();
		bool IsEmpty();
		void Push(string Text);
		void Pop(string &Text);
		void Top(string &Text);
		int GetLength();
		void Print();

	private:
		StackNode *Head;
		int Length;
};

