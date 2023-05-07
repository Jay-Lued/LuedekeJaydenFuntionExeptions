//Jayden Luedeke
//Cis 1202
//May 7, 2023

#include <iostream>

using namespace std;

class NotLetter_C
{
public:
	string Throw_Not_Letter()
	{
		return ("Start character is not a letter: re-enter number\n");
	}
};

class NotRange_C
{
public:
	string Out_Of_Bounds()
	{
		return ("New character is out of bounds: re-enter number\n");
	}
};



char character(char& start, int offset);

int main()
{
	char choice;
	int offset;
	bool again = true;

	while (again)
	{
		cout << "Please enter starting letter: ";
		cin >> choice;
		cout << "Please enter offset: ";
		cin >> offset;

		try
		{
			character(choice, offset);

			cout << endl << "New letter: " << choice;

			cout << endl << "Again? 1 for yes, 0 for no: ";
			cin >> again;
		}
		catch (NotLetter_C& msg)
		{
			cout << msg.Throw_Not_Letter();
		}
		catch (NotRange_C& msg)
		{
			cout << msg.Out_Of_Bounds();
		}
	}

	return 0;
}

char character(char& start, int offset)
{
	if (offset > 25 || offset < -25)
	{
		throw NotRange_C();
	}
	
	if ((start < 65 || start > 90) && (start < 97 || start > 122))
	{
		throw NotLetter_C();
	}

	start += offset;

	if ((start < 65 || start > 90) && (start < 97 || start > 122))
	{
		throw NotRange_C();
	}

	return start;
}