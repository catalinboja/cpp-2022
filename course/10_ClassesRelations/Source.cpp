#include <iostream>
#include <string>
using namespace std;

class PersonalData {
public:
	PersonalData() {
		cout << endl << "Default ctor PersonalData";
	}
	string name;
	string address;
	string cnp;
	int age;
};

class Faculty {
public:
	string faculty;
	string facultyAddress;
	int streetNo;
	int* pointer = nullptr;

public:
	Faculty() {
		cout << endl << "Default ctor Faculty";
	}

	Faculty(string faculty): faculty(faculty) {
		cout << endl << "Ctor Faculty";
	}

	~Faculty() {
		delete[] this->pointer;
	}
};

class Grade {

	int grade;
	string course;
public:
	Grade() {
		//cout << endl << "Default ctor Grade";
	}
};


//has a relation
class Student {
public:
	PersonalData personalData;
	Faculty faculty;
	Grade grades[100];
	int noGrades;
public:
	Student():faculty("CSIE")  {

	}

	~Student() {
	}

	void takeExam(Grade grade) {

	}

	void operator+=(Grade grade) {

	}

	void doSomething() {
		this->faculty.facultyAddress = "Bucharest";
	}
};


//is a 
class MasterStudent : public Student {
	string bachelorDiploma;
	float bachelorAverage;
};


int main() {

	Student student;
	Grade grade;
	student += grade;

	MasterStudent masterStudent;

}