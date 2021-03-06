// week6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int countLetters(char ph[500]);
int countWords(char ph[500]);
void reverseIt(char ph[500]);
bool isPal(char ph[500]);

int main()
{
	char phrase[500];

	cout << "please neter a phrase: ";
	cin.getline(phrase, 500);

	cout << "your phrase has " << countLetters(phrase) << " letters." << endl;
	cout << "your phrase has " << countWords(phrase) << " words." << endl;

	reverseIt(phrase);
	cout << "your phrase reversed is " << phrase << endl;

	if (isPal(phrase))
		cout << "its a palindrome!!!" << endl;
	else
		cout << "its not a palindrome..." << endl;

	return 0;
}

bool isPal(char ph[500])
{
	int begin = 0;
	int end = strlen(ph) - 1;
	

	for (; begin < end; begin++, end--)
	{
		if (ph[begin] !=  ph[end] )
			return false;
	}
	return true;
}

void reverseIt(char ph[500])
{
	int begin = 0;
	int end = strlen(ph) - 1;
	char temp;

	for (/*begin = 0*/; begin < end; begin++, end--)
	{
		temp = ph[end];
		ph[end] = ph[begin];
		ph[begin] = temp;
	}
}

int countWords(char ph[500])
{
	int i;
	int count = 0;
	bool inword = false;

	for (i = 0; i < strlen(ph); i++)
	{
		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z') || ph[i] == '\'')
		{
			if (!inword)
			{
				count++;
				inword = true;
			}
		}
		else
		{
			inword = false;
		}
	}
	return count;
}

int countLetters(char ph[500])
{
	int i;
	int count = 0;
	
	for (i = 0; ph[i] != '\0'; i++)
	{
		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z'))
			count++;
	}
	
	return count;
}