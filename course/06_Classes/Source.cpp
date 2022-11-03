#include <iostream>
#include <string>
using namespace std;


//global variable
//const int MINIMUM_NAME_SIZE = 3;

class Student {
private:
	string name = "John Doe"; //char* name | char name[100]
	int* grades = nullptr;
	int noGrades = 0;

	const static int MINIMUM_NAME_SIZE = 3;
	const static int MINIMUM_GRADE = 1;
	const static int MAXIMUM_GRADE = 10;
	static int NO_STUDENTS_OBJECTS;


public:
	//public interface of the class
	string getName() {
		return this->name;
	}

	void setName(string name) {
		//should have at least 3 chars
		if (name.size() < Student::MINIMUM_NAME_SIZE) {
			throw "Wrong name. Too short";
		}
		//shadowing
		//name = name;
		this->name = name;
	}

	//this is wrong
	//int* getGrades() {
	//	return this->grades;
	//}

	int* getGrades() {
		//create a copy and return the pointer to it
		int* copy = 
			this->copyArray(this->grades, this->noGrades);
		return copy;

	}

	void setGrades(int* newGrades, int noNewGrades) {

		if (noNewGrades <= 0) {
			throw "Number of grades is not ok";
		}
		if (newGrades == nullptr) {
			throw "Grades pointer is not ok";
		}

		for (int i = 0; i < noNewGrades; i++) {
			if (newGrades[i] < Student::MINIMUM_GRADE || newGrades[i] > Student::MAXIMUM_GRADE) {
				throw "Grade not ok";
			}
		}

		if (this->grades != nullptr)
			delete[] this->grades;
		this->grades = new int[noNewGrades];
		for (int i = 0; i < noNewGrades; i++) {
			this->grades[i] = newGrades[i];
		}
		this->noGrades = noNewGrades;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	void print() {
		cout << endl << "Grades for " << this->name;
		for (int i = 0; i < this->noGrades; i++) {
			cout << " " << this->grades[i];
		}
	}

private:
	int* copyArray(int* array, int noElements) {
		int* copy = new int[noElements];
		for (int i = 0; i < noElements; i++) {
			copy[i] = array[i];
		}
		//an alternative
		//memcpy(copy, copy, noElements * sizeof(int));
		return copy;
	}
};


//init the static non-const variable
int Student::NO_STUDENTS_OBJECTS = 0;

int main() {
	Student student;
	Student alice;
	//cout << endl << "Student name is " << student.name;
	cout << endl << "Student name is " << student.getName();
	cout << endl << "Student name is " << alice.getName();

	student.setName("John");
	cout << endl << "Student name is " << student.getName();
	//alice.setName("Al");
	//cout << endl << "Student name is " << alice.getName();

	alice.setName("Alice");
	int grades[] = { 9,10,10 };

	alice.setGrades(grades, 3);

	cout << endl << "Grades for " << alice.getName();
	int* studentGrades = alice.getGrades();
	for (int i = 0; i < alice.getNoGrades(); i++) {
		cout << " " << studentGrades[i];
	}

	studentGrades[0] = 10;

	//cout << endl << "Grades for " << alice.getName();
	//studentGrades = alice.getGrades();
	//for (int i = 0; i < alice.getNoGrades(); i++) {
	//	cout << " " << studentGrades[i];
	//}

	alice.print();
}