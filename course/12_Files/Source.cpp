#include <iostream>
#include <string>
#include <fstream>
using namespace std;


enum Type {STUDENT, MASTER, PHD};

class Student {
	string name = "";
	int age = 0;
	int* grades = nullptr;
	int noGrades = 0;

public:

	Student(string name, int age, int* grades, int noGrades)
		:name(name), age(age), noGrades(noGrades)
	{
		if (noGrades > 0) {
			this->grades = new int[this->noGrades];
			memcpy(this->grades, grades,
				sizeof(int) * noGrades);
		}
		else {
			this->grades = nullptr;
		}
	}

	Student(const Student& student) 
		:name(student.name), age(student.age), 
		noGrades(student.noGrades) {

		if (this->noGrades != 0) {
			this->grades = new int[this->noGrades];
			memcpy(this->grades, student.grades,
				sizeof(int) * noGrades);
		}
		else 
			this->grades = nullptr;
	}

	Student operator=(Student student) {
		if (this == &student) {
			return *this;
		}
		delete[] this->grades;

		this->age = student.age;
		this->name = student.name;
		this->noGrades = student.noGrades;

		if (this->noGrades != 0) {
			this->grades = new int[this->noGrades];
			memcpy(this->grades, student.grades,
				sizeof(int) * noGrades);
		}
		else {
			this->grades = nullptr;
		}

		return *this;
	}



	~Student() {
		delete[] this->grades;
	}

	//pre
	Student operator++() {
		this->age += 1;
		return *this;
	}

	//post
	Student operator++(int) {
		Student copie = *this;
		this->age += 1;
		return copie;
	}

	friend ostream& operator<<(ostream&, Student& student);
};

ostream& operator<<(ostream& out, Student& student) {
	out << endl << "Student data: ";
	out << endl << "Name: " << student.name;
	out << endl << "Age: " << student.age;
	if (student.grades != nullptr) {
		out << endl << "Grades: ";
		for (int i = 0; i < student.noGrades; i++) {
			out << student.grades[i] << " ";
		}
	}
	else {
		out << endl << "No grades, yet.";
	}
	return out;
}

void operator>>(fstream& file, Student& student) {

}

Type convertToType(int value) {
	switch (value)
	{
	case 0:
		return Type::STUDENT;
	case 1:
		return Type::MASTER;
	case 2:
		return Type::PHD;
	default:
		throw "Undefined type";
	}
}

string convertToString(Type value) {
	switch (value)
	{
	case Type::STUDENT:
		return "Student";
	case Type::MASTER:
		return "Master";
	case Type::PHD:
		return "Phd";
	default:
		return "Undefined type";
	}
}

Student** readStudents(string fileName, int& noStudents) {
	Student** students = nullptr;
	noStudents = 0;

	fstream studentsInput(fileName, ios::in);
	if (studentsInput.is_open()) {
		string name;
		int age;
		int* grades;
		int noGrades;

		//read no students
		studentsInput >> noStudents;

		if (noStudents > 0) {
			students = new Student * [noStudents];
		}

		for (int i = 0; i < noStudents; i++) {
			studentsInput >> name;
			studentsInput >> age;
			studentsInput >> noGrades;
			if (noGrades != 0) {
				grades = new int[noGrades];
				for (int j = 0; j < noGrades; j++) {
					studentsInput >> grades[j];
				}
			}
			else {
				grades = nullptr;
			}

			students[i] = new Student(name, age, grades, noGrades);
		}

		studentsInput.close();
	}
	
	return students;
}

int main() {

	int grades[] = { 10,10,9 };
	int noGrades = 3;

	Student john("John", 21, grades, noGrades);
	Student alice("Alice", 20, grades, noGrades);

	Student clonaJohn = john;
	Student* clonaJohnInHeap = new Student(john);

	//cout << john;
	cout << john << alice;



	int vb1 = 10;
	int vb2 = vb1++;	//vb2 = 11, vb1 = 11
	int vb3 = vb1++;	//vb3 = 11, vb1 = 12

	++vb1;
	vb1++;


	Student rezultat = john++;  //incrementeaza varsta
	rezultat = ++john;			//incrementeaza varsta


	//john += 10;
	//rezultat = john += 10;

	rezultat = alice = john;

	Type type = Type::PHD;
	cout << endl << 
		"Student type (0 - Student, 1 - Master, 2 - Phd):";
	//cin >> type;
	int studentType;
	cin >> studentType;
	type = convertToType(studentType);

	cout << endl << "Type is " << type;
	cout << endl << "Type is " << convertToString(type);

	fstream file("report.txt",ios::out | ios::app);
	fstream backup;
	backup.open("students.data",
		ios::out | ios::binary);

	//writing into text files
	if (file.is_open()) {
		file << endl << "Students list";
		file << john;
		file << alice;
		file.close();
	}
	else {
		cout << endl << "******** No file for report *******";
	}

	//reading from text files
	//one line one value
	//number of elements before a variable list of values
	//ifstream studentsInput("students.txt");

	Student** students = nullptr;
	int noStudents = 0;

	fstream studentsInput("students.txt", ios::in);
	if (studentsInput.is_open()) {
		string name;
		int age;
		int* grades;
		int noGrades;

		//read no students
		studentsInput >> noStudents;

		if (noStudents > 0) {
			students = new Student*[noStudents];
		}

		for (int i = 0; i < noStudents; i++) {
			studentsInput >> name;
			studentsInput >> age;
			studentsInput >> noGrades;
			if (noGrades != 0) {
				grades = new int[noGrades];
				for (int j = 0; j < noGrades; j++) {
					studentsInput >> grades[j];
				}
			}
			else {
				grades = nullptr;
			}

			students[i]  = new Student(name, age, grades, noGrades);
		}

		studentsInput.close();
	}
	else {
		cout << endl << "*********** NO students.txt";
	}

	delete[] students;

	students = readStudents("students.txt", noStudents);


	cout << endl << "Students data from file:";
	for (int i = 0; i < noStudents; i++) {
		cout << endl << *students[i];
	}

}

