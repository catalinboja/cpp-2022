
#include <string>

enum StudentType { BACHELOR = 4, MASTER = 3, PHD = 5};

class Student {
private:
	char* name  = nullptr;
	std::string address = "";		//char* address
	char faculty[100] = "";
	int noGrades = 0;
	int* grades = nullptr;
	bool hasScholarship = false;
	int age = 0;
	int credits[100];
	int noCourses = 0;
	std::string* courses = nullptr;	//char* * courses;

public:
	int getAge() {
		return this->age;
	}


	//is not OK
	char* getName() {
		return this->name;
	}

	char* getFaculty() {
		return this->faculty;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	std::string getAddress() {
		return this->address;
	}

	bool hasScholarship() {
		return this->hasScholarship;
	}

	void addGrade(int newGrade) {
		//this->noGrades = no;
		//add the new grade to the array
	}

};

int main() {
	Student john;
	//john.noGrades = 10;
	john.getAge();
}