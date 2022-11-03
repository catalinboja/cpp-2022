#define _CRT_SECURE_NO_WARNINGS
#include <string>

enum StudentType { BACHELOR = 4, MASTER = 3, PHD = 5 };

class Student {
private:
	char* name = nullptr;
	std::string address = "";		//char* address
	char faculty[100] = "";

	bool hasScholarship = false;
	int age = 0;

	int noCourses = 0;
	int credits[100];
	int* grades = nullptr;
	std::string* courses = nullptr;	//char* * courses;

public:

	const static int MIN_NAME_SIZE = 3;
	const static int MIN_STRING_SIZE = 5;
	const static int MIN_AGE = 5;
	const static int MAX_AGE = 120;

	//Student() {

	//}

	//ctor with arguments
	Student(const char* name, std::string address, int age, const char* faculty) {
		this->setName(name);
		this->setAddress(address);
		this->setAge(age);
		this->setFaculty(faculty);
	}

	//Student(const char* name, std::string address, int age) {
	//	this->setName(name);
	//	this->setAddress(address);
	//	this->setAge(age);
	//}

	Student(const char* name, std::string address, int age = Student::MIN_AGE) {
		this->setName(name);
		this->setAddress(address);
		this->setAge(age);
	}

	void setName(const char* name) {

		if (strlen(name) < Student::MIN_NAME_SIZE) {
			throw "Invalid name";
		}
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setAddress(std::string address) {
		if (address.size() < Student::MIN_STRING_SIZE) {
			throw "Address too short";
		}
		this->address = address;
	}

	void setAge(int age) {
		if (age < Student::MIN_AGE || age > Student::MAX_AGE) {
			throw "Invalid age";
		}
		this->age = age;
	}

	void setFaculty(const char* faculty) {
		if (strlen(faculty) < Student::MIN_STRING_SIZE) {
			throw "Invalid faculty name";
		}
		strcpy(this->faculty, faculty);
	}

	int getAge() {
		return this->age;
	}


	//return a copy of the value 
	//NOT the initial pointer
	char* getName() {
		//return this->name;
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy(nameCopy, this->name);
		return nameCopy;
	}

	char* getFaculty() {
		//not ok
		//you return the address of an array placed on this method stack
		//char facultyCopy[100];
		//strcpy(facultyCopy, this->faculty);
		//return facultyCopy;

		char* facultyCopy = new char[strlen(this->faculty) + 1];
		strcpy(facultyCopy, this->faculty);
		return facultyCopy;

	}

	int getNoCourses() {
		return this->noCourses;
	}

	std::string getAddress() {
		return this->address;
	}

	bool hasActualScholarship() {
		return this->hasScholarship;
	}

	int* getCredits() {
		int* creditsCopy = new int[this->noCourses];
		for (int i = 0; i < this->noCourses; i++) {
			creditsCopy[i] = this->credits[i];
		}
		return creditsCopy;
	}

	int* getGrades() {
		int* gradesCopy = new int[this->noCourses];
		memcpy(gradesCopy, this->grades,
			this->noCourses * sizeof(int));
		return gradesCopy;
	}

	//void addGrade(int newGrade) {
	//	//this->noGrades = no;
	//	//add the new grade to the array
	//}

	//add a new course, with credits and a default grade
	void registerForCourse(std::string course, int credits) {
		std::string* newCourses = new std::string[this->noCourses + 1];
		int* newGrades = new int[this->noCourses + 1];
		
		for (int i = 0; i < this->noCourses; i++) {
			newCourses[i] = this->courses[i];
			newGrades[i] = this->grades[i];
		}
		newCourses[this->noCourses] = course;
		delete[] this->courses;
		this->courses = newCourses;
		this->credits[this->noCourses] = credits;

		newGrades[this->noCourses] = 0;
		delete this->grades;
		this->grades = newGrades;

		this->noCourses += 1;

	}

};

int main() {
	Student john("John","Bucharest",19);
	//john.noGrades = 10;
	john.getAge();

	Student alice("Alice", "Bucharest", 19, "CSIE");

	alice.registerForCourse("OOP", 5);
}