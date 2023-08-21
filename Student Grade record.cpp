#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


struct student
{
	string name;
	float grade;
};

class grade_manager
{
	static const int max_students = 100;
	student students[max_students];
	int numstudents = 0;

public:
	void input_students(int num)
	{
		numstudents = num;
		for (int i = 0; i < numstudents; ++i)
		{
			cout << i + 1 << "Name: ";
			cin >> students[i].name;
			cout << i + 1 << "Grade: ";
			cin >> students[i].grade;
		}
	}
	void calculate_avg()
	{
		float totalgrade = 0.0;
		float highestgrade = students[0].grade;
		float lowestgrade = students[0].grade;
		int highestindex = 0;
		int lowestindex = 0;


		for (int i = 0; i < numstudents; ++i)
		{
			totalgrade += students[i].grade;

			if (students[i].grade>highestgrade)
			{
				highestgrade = students[i].grade;
				highestindex = i;
			}

			if (students[i].grade < lowestgrade)
			{
				lowestgrade = students[i].grade;
				lowestindex = i;
			}

		}

		float avg_grade = totalgrade / numstudents;
		cout << fixed << setprecision(2);
		cout << "\nAverage Grade: " << avg_grade;
		cout << "\nHighest Grade: " << highestgrade << "(Student Name: " << students[highestindex].name << ", Roll #: " << highestindex + 1 << ") \n";
		cout << "\nLowest Grade: " << lowestgrade << "(Student Name: " << students[lowestindex].name << ", Roll #: " << lowestindex + 1 << ") \n";
	}
};


int main()
{
	grade_manager g;
	int t_students;
	cout << "Enter total students: ";
	cin >> t_students;
	g.input_students(t_students);
	g.calculate_avg();


	system("pause");
	return 0;
}