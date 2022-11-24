#include <iostream>
#include <string>
using namespace std;


//global variable
//const int MINIMUM_NAME_SIZE = 3;

class Utility {
public:
	static int* copyArray(int* array, int noElements) {
		int* copy = new int[noElements];
		for (int i = 0; i < noElements; i++) {
			copy[i] = array[i];
		}
		//an alternative
		//memcpy(copy, copy, noElements * sizeof(int));
		return copy;
	}

};

class Student {
private:
	const int id;
	string name = "John Doe"; //char* name | char name[100]
	int* grades = nullptr;
	int noGrades = 0;

	static int NO_STUDENTS_OBJECTS;

public:

	const static int MINIMUM_NAME_SIZE = 3;
	const static int MINIMUM_GRADE = 1;
	const static int MAXIMUM_GRADE = 10;

	//default the ctor
public:
	Student() : id(0), name("Unknown") {

		//this->id = 0;

		cout << endl << "Default ctor";

		Student::NO_STUDENTS_OBJECTS += 1;

		//this->name = "Unknown";

		this->setName("Unknown");
	}
public:
	//ctor with arguments
	Student(int ID, string name) : id(ID), name(name) {
		//this->setName(name);
		//check the id
		//if id is not ok throw an error
		Student::NO_STUDENTS_OBJECTS += 1;
	}

	Student(int Id, string name, int* grades, int noGrades)
		:id(Id) {
		this->setName(name);
		this->setGrades(grades, noGrades);
		Student::NO_STUDENTS_OBJECTS += 1;
	}


	//other with different order for the arguments
	//not necessary as you already have the previous one
	Student(int Id, int* grades, int noGrades, string name) : id(Id) {
		this->setName(name);
		this->setGrades(grades, noGrades);
		Student::NO_STUDENTS_OBJECTS += 1;
	}

	//class destructor
	~Student() {
		cout << endl << "Student destructor";
		this->deleteGrades();

		Student::NO_STUDENTS_OBJECTS -= 1;
	}

	//copy constructor
	Student(const Student& student) : id(student.id) {
		//student.name = this->name;
		cout << endl << "The copy constructor";
		//this->grades = student.grades;
		this->setName(student.name);
		this->setGrades(student.grades, student.noGrades);
	}


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
			Utility::copyArray(this->grades, this->noGrades);
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

	static int getNoStudentsInMemory() {
		//this does not exist here
		return Student::NO_STUDENTS_OBJECTS;
	}

	void operator=(const Student& source) {

		if (this == &source) {
			cout << endl << "they are the same";
			return;
		}

		//if (this->id == source.id && this->name == source.name) {
		//	cout << endl << "They are the same object";
		//	return;
		//}

		//source.name = this->name;

		this->name = source.name;
		//this->id = source.id;

		//if (this->grades != nullptr) {
		//	delete[] this->grades;
		//	this->grades = nullptr;
		//}

		this->setGrades(source.grades, source.noGrades);


	}


public:

	//make the default ctor private;
	//Student() {
	//cout << endl << "Calling Student default ctor";
	//}

	void deleteGrades() {
		if (this->grades != nullptr) {
			delete[] this->grades;
			this->noGrades = 0;
			this->grades = nullptr;
		}
	}

	bool operator==(Student student) {
		if (this->id == student.id && this->name == student.name) {
			return true;
		}
		else {
			return false;
		}
	}

	friend void operator<<(ostream& out, Student stud);

};

Student operator*(Student& stud, int value) {
	Student result = stud;
	int* grades = stud.getGrades();
	int* newGrades = new int[stud.getNoGrades() * value];
	for (int i = 0; i < stud.getNoGrades(); i++) {
		newGrades[i] = grades[i];
		for (int j = 0; j < value; j++) {
			newGrades[j + stud.getNoGrades()] = grades[i];
		}
	}
	result.setGrades(newGrades, stud.getNoGrades() * value);
}

Student operator*(int value, Student& stud) {
	return stud * value;
}

void operator<<(ostream& out, Student stud) {
	out << stud.name;
	//...
}




//init the static non-const variable
int Student::NO_STUDENTS_OBJECTS = 0;




int main() {
	int grades[] = { 9,10,10 };

	Student john(1, "John", grades, 3);

	Student alice(2, "Alice", grades, 3);

	alice.print();

	Student copy = alice;

	//Student students[10];

	Student staticArray[10];
	Student* dynamicArray = new Student[10];

	Student* students[10];
	Student** studentsPointers;
	studentsPointers = new Student * [10];

	students[0] = new Student(1, "Alice");
	students[1] = new Student(2, "Bob");

	//mathematical ops: +, -, *, /, +=, -=, *=, /=, ++ (post and pre), -- 
	//conditional ops: <, >, <=, >=, ==, !=
	//logic operators: !, ||, &&
	//stream ops: <<, >>
	//index operator: []
	//function operator: ()
	//assignment operator: =

	//alice = john;
	//operator=(Student & destination, Student source);
	//alice.operator=(john)

	//alice = alice;

	alice = alice * 2;
	alice = 2 * alice;

	if (alice == john) {
		cout << endl << "They are the same !";
	}

	cout << alice;

}