#include<iostream>
using namespace std;

class calculator
{
	double num1, num2;
	char operation;
public:
	void getinput()
	{
		cout << "Enter 1st number: ";
		cin >> num1;
		cout << "Enter 2nd number: ";
		cin >> num2;
		cout << "Enter operation: ";
		cin >> operation;
	}

	void calculation()
	{
		double result;
		while (true)
		{
			if (operation == '+')
			{
				result = num1 + num2;
				break;
			}

			else if (operation == '-')
			{
				result = num1 - num2;
				break;
			}
			else if (operation == '*')
			{
				result = num1 * num2;
				break;
			}
			else if (operation == '/')
			{
				if (num2 != 0)
				{
					result = num1 / num2;
					break;
				}
				else
				{
					cout << "Mathematical error" << endl;
					return;
				}
			}
			else
			{
				cout << "Invalid operation\nEnter a valid operator: ";
				cin >> operation;
			}
		}

		cout << "Result: " << result << endl;
	}
};

int main()
{
	calculator c;
	c.getinput();
	c.calculation();

	system("pause");
	return 0;
}