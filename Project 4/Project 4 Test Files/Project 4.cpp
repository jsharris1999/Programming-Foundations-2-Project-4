#include "StringStack.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream din;
	char NextChar;
	string StackString = "";
	string PreviousStack = "";
	bool Pop = false;
	StringStack Tags;
	din.open("input.txt");
	if (din.fail() == 0)
	{
		while (!din.eof())
		{
			din.get(NextChar);
			if (NextChar == '<')
			{
				while (NextChar != '>' && NextChar != ' ')
				{
					din.get(NextChar);
					if (NextChar == '/')
					{
						Pop = true;
					}
					if (NextChar != '>' && NextChar != ' ' && NextChar != '/')
					{
						StackString += NextChar;
						//cout << NextChar << endl;
					}
				}
				if (Pop == true)
				{
					if (StackString == PreviousStack)
					{
						Tags.Pop(StackString);
						Tags.Top(PreviousStack);
					}
					else
					{
						cout << "Tag error detected regarding the " << PreviousStack << " tag." << endl;
						return 0;
					}
				}
				else if (Pop == false)
				{
					if (StackString.compare("br") != 0 && StackString.compare("hr") != 0 && StackString.compare("embed") != 0 && StackString.compare("img") != 0 && StackString.compare("link") != 0 && StackString.compare("source") != 0)
					{
						Tags.Push(StackString);
						Tags.Top(PreviousStack);
					}
				}
				StackString = "";
				Pop = false;
				Tags.Print();
			}
		}
		if (Tags.IsEmpty() != 1)
		{
			cout << "The following tags have no corresponding end tag." << endl;
			Tags.Print();
		}
	}
	return 0;
}