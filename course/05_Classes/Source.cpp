#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student {
	int age = 0;
	char* name = nullptr; //same as NULL in C
	float height = 0;
	char address[50];
};

struct MasterStudent {
	int age = 0;
	char* name = nullptr; //same as NULL in C
	float height = 0;
	float bachelorExamAverage;
};

void printStudent(Student student) {
	if (student.name == nullptr) {
		cout << endl << "The student has no name";
	}
	else
	{
		cout << endl << "Student name is " << student.name;
	}
	cout << endl << "Student age is " << student.age;
	cout << endl << "Student height is " << student.height;
}

void setStudentName(const char* name, Student& student) {
	if (student.name != nullptr) {
		delete[] student.name;
	}
	student.name = new char[strlen(name) + 1];
	strcpy(student.name, name);

}

class StudentClass {
	//you get it by default
private:	//access specifiers
	int age = 0;
	char* name = nullptr; //same as NULL in C
public:		//access specifier
	float height = 0;
private:
	char address[50];
protected:	//has a meaning for inheritance
public:

	//constructors
	StudentClass(int age, const char* name, float height) {
		//shadowing
		//age = age;

		//this->age = age;
		this->setAge(age);
		this->setName(name);
		this->height = height;

	}

	//default ctor
	StudentClass() {

	}

	void printStudentAge() {
		cout << endl << "The student object age is " << this->age;
	}

	//accessor method = a getter
	//provides read access
	int getAge() {
		return this->age;
	}

	//accessor method = a setter
	//provides write access
	void setAge(int newValue) {
		if (newValue >= 10 && newValue <= 110) {
			this->age = newValue;
		}
		else {
			//cout << endl << "Error";
			throw "Invalid value";
		}
	}

	void setName(const char* newName) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
	}
};

int main() {

	Student* students = new Student[10];
	printStudent(students[0]);
	setStudentName("John", students[0]);
	printStudent(students[0]);

	Student student;	//an article

	student.age = -23;
	StudentClass studentObject; //an object
	//studentObject.age = -23;
	//int age = studentObject.age;
	studentObject.height = 180;

	StudentClass john;

	cout << endl << " ------------------- ";
	studentObject.printStudentAge();
	john.printStudentAge();
	//printStudentAge(studentObject);

	int johnAge = john.getAge();
	//john.setAge(-23);
	john.setAge(23);

	StudentClass alice(22, "Alice", 175);
	alice.printStudentAge();
}
