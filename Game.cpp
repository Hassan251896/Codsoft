#include<iostream>
#include<limits>
#include<ctime>

using namespace std;

class Guess_Number
{
	int secretnum;
	int remattempts;
public:

	Guess_Number()
	{
		secretnum = Generate_num();
		remattempts = 5;
	}

	int Generate_num()
	{
		unsigned int seed = static_cast<unsigned int>(time(nullptr));
		seed = (seed * 32719 + 3) % 32749;
		return seed % 100 + 1;
	}

	void run()
	{
		cout << "________ GUESS THE NUMBER ________\n";
		int guess;
		while (remattempts > 0)
		{
			cout << "Guess the number between 1 to 100 \n Remaining attempts: " << remattempts << ": ";
			cin >> guess;

			if (cin.fail())
			{
				cout << "Invalid input\n Enter a valid number\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
				continue;
			}
			remattempts--;

			if (guess < secretnum)
			{
				cout << "TOO LOW! ";
			}
			else if (guess>secretnum)
			{
				cout << "TOO HIGH! ";
			}
			else
			{
				cout << "Congratulations! You guessed the correct number in : " << 5 - remattempts << "attempts: " << endl;
			}
			if (remattempts > 0)
			{
				cout << "Try again\n";
			}
			else
			{
				cout << "You lose the game \n The correct number was " << secretnum << ".\n";
			}
		}
	}
};


int main()
{
	Guess_Number g;
	g.run();

	system("pause");
	return 0;
}