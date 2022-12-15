#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	string name = "";
	int age = 0;
	string faculty = "";
	int* grades = nullptr;
	int noGrades = 0;

public:
	Student(string name, int age, string faculty, int* grades, int noGrades)
		:name(name), age(age), faculty(faculty), noGrades(noGrades) {
		if (grades != nullptr) {
			this->grades = new int[noGrades];
			memcpy(this->grades, grades, sizeof(int) * noGrades);
		}
		cout << endl << "Student ctor";
	}

	Student() {
		cout << endl << "Student default ctor";
	}

	~Student() {
		delete[] this->grades;
		cout << endl << "Student destructor";
	}

	string getName() {
		return this->name;
	}

	virtual void doSomething() {
		cout << endl << "Student does something";
	}

	//TODO: copy ctor, operator =
};

//is a relation = inheritance

class MasterStudent : public Student
{
	string bachelorThesisTitle;
	float bachelorExamGrade;
	string masterProgram;
public:
	//string getName() {
	//	return this->getName();
	//}

	MasterStudent() {
		cout << endl << "MasterStudent default ctor";
	}

	int getAge() {
		return this->age;
	}

	~MasterStudent() {
		//PLEASE DON'T
		//delete[] this->grades;
		//this->grades = nullptr;
		cout << endl << "MasterStudent destructor";
	}

	//override methods inherited from the parent class
	void doSomething() {
		cout << endl << "Master student does something";
	}

	//for the downcasting
	void operator=(Student student) {

	}
};
int main() {
	Student john;
	//student.age = 23;
	string studentName = john.getName();
	MasterStudent alice;
	string name = alice.getName();

	john.doSomething();
	alice.doSomething();

	//Student students[10];
	//MasterStudent masterStudents[10];

	Student allOfThem[10];
	allOfThem[0] = john;
	allOfThem[1] = alice;

	cout << endl << "************************";

	allOfThem[0].doSomething();
	allOfThem[1].doSomething();

	Student* pointers[2];
	pointers[0] = &john;
	pointers[1] = &alice;

	pointers[0]->doSomething();
	pointers[1]->doSomething();




	//john = alice;   //UP CASTING - works by default
	//
	//alice = john;    //DOWN CASTING

	//masterStudents[0] = john;
	//masterStudents[1] = alice;



}