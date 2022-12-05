#include <iostream>
#include <string>

using namespace std;

class Student {
	const int id;
	string name;
	int grades[100];
	int noGrades = 0;
public:
	Student(int id, string name) : id(id), name(name) {

	}

	const Student& operator=(const Student& other) {
		if (this == &other)
			return other;
		this->name = other.name;
		return other;
	}

	void doSomething() {

	}

	int operator()(int gradeLimit) {
		int counter = 0;
		for (int i = 0; i < this->noGrades; i++) {
			if (this->grades[i] > gradeLimit) {
				counter += 1;
			}
		}
		return counter;
	}

	int operator()(int minLimit, int maxLimit) {
		int counter = 0;
		for (int i = 0; i < this->noGrades; i++) {
			if (this->grades[i] > minLimit && this->grades[i] < maxLimit) {
				counter += 1;
			}
		}
		return counter;
	}
};

ostream& operator<<(ostream& out, Student& student) {

	return out;
}

int main() {
	Student student1(1, "John");
	Student student2(2, "Alice");
	Student student3(2, "John Doe");

	student2 = student1;

	int vb1, vb2, vb3;
	vb1 = (vb2 = (vb3 = 10));

	student3 = student2 = student1;

	cout << student1;
	cout << student1 << student2;

	student1.doSomething();

	int noGradesAbove5 = student1(5);
	int noGradesAbove5AndLessThan8 = student1(5, 8);

}