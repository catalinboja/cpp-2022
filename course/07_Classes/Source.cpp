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
		string name = "John Doe"; //char* name | char name[100]
		int* grades = nullptr;
		int noGrades = 0;

		static int NO_STUDENTS_OBJECTS;

	public:

		const static int MINIMUM_NAME_SIZE = 3;
		const static int MINIMUM_GRADE = 1;
		const static int MAXIMUM_GRADE = 10;

		//default the ctor
	private:
		Student() {

			cout << endl << "Default ctor";
			
			Student::NO_STUDENTS_OBJECTS += 1;

			this->name = "Unknown";

			this->setName("Unknown");
		}
	public:
		//ctor with arguments
		Student(string name) {
			this->setName(name);
			Student::NO_STUDENTS_OBJECTS += 1;
		}

		Student(string name, int* grades, int noGrades) {
			this->setName(name);
			this->setGrades(grades, noGrades);
			Student::NO_STUDENTS_OBJECTS += 1;
		}


		//other with different order for the arguments
		//not necessary as you already have the previous one
		Student(int* grades, int noGrades, string name) {
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

		//copy construction
		Student(Student& student) {
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


	private:

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
	};


	//init the static non-const variable
	int Student::NO_STUDENTS_OBJECTS = 0;



int main() {
	int grades[] = { 9,10,10 };

	//Student student;
	//TO DO: init it
	//student.setName("Vader");

	Student anonymous("Anonymous");

	Student john("John");
	Student alice("Alice", grades, 3);


	//for (;;) {

	//	//Student temp("Temp", grades, 3);
	//	//temp.deleteGrades();
	//	Student* studentInHeap = new Student("Bob");
	//	delete studentInHeap;s
	//}

	//Student* studentInHeap = new Student("Bob");
	//delete studentInHeap;

	Student bianca = alice;
	bianca.setName("Bianca");

	alice.print();
	bianca.print();


}