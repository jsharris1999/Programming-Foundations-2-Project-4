#include "StringStack.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

StringStack::StringStack()
{
	Head = NULL;
	Length = 0;
}

StringStack::StringStack(const StringStack & stack)
{
	// Create first node
	StackNode *copy = new StackNode();
	Head = copy;

	// Walk list to copy nodes
	StackNode *ptr = stack.Head;
	while (ptr != NULL)
	{
		copy->Next = new StackNode();
		copy = copy->Next;
		copy->Text = ptr->Text;
		copy->Next = NULL;
		ptr = ptr->Next;
	}

	// Tidy first node
	copy = Head;
	Head = copy->Next;
	delete copy;
}

StringStack::~StringStack()
{
	// Walk stack deleting data
	while (Head != NULL)
	{
		StackNode *Temp = Head;
		Head = Head->Next;
		delete Temp;
	}

	// Reset head
	Head = NULL;
	Length = 0;
}

bool StringStack::IsFull()
{
	return (false);
}

bool StringStack::IsEmpty()
{
	return (Length == 0);
}

void StringStack::Push(string Text)
{
	// Check for full stack
	if (IsFull())
		return;

	// Allocate space for data
	StackNode *Temp = new StackNode;
	if (Temp == NULL)
		return;

	// Insert data at head of list
	Temp->Text = Text;
	Temp->Next = Head;
	Head = Temp;
	Length++;
}

void StringStack::Pop(string &Text)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Extract information from node
	Text = Head->Text;

	// Pop item from linked list
	StackNode *Temp = Head;
	Head = Head->Next;
	delete Temp;
	Length--;
}

void StringStack::Top(string &Text)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Return information from node
	Text = Head->Text;
}

int StringStack::GetLength()
{
	return Length;
}

void StringStack::Print()
{
	// Walk the stack printing data
	cout << "Tags: ";
	StackNode *Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->Text << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}
