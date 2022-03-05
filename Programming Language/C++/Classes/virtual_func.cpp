#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Problem: https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true

class Person
{
public:
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person
{
private:
	int cur_id;
	static int id;
	string name;
	int age;
	int publications;

public:
	void getdata()
	{
		this->cur_id = Professor::id;

		Professor::id++;
		cin >> name >> age >> publications;
	}

	void putdata()
	{
		cout << name << " " << age << " " << publications << " " << cur_id;
		cout << endl;
	}
};

int Professor::id = 1;

class Student : public Person
{
private:
	int cur_id;
	static int id;
	string name;
	int age;
	vector<int> scores;

public:
	void getdata()
	{
		this->cur_id = Student::id;
		Student::id++;

		cin >> name >> age;
		for (int i = 1; i <= 6; i++)
		{
			int score;
			cin >> score;

			this->scores.push_back(score);
		}
	}

	void putdata()
	{
		// sum the score
		int sum = 0;
		for (int s : scores)
		{
			sum += s;
		}

		cout << name << " " << age << " " << sum << " " << cur_id << endl;
	}
};

int Student::id = 1;

int main()
{
	int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}